#include "Application.hpp"
#include <Metal/Metal.h>
#include <AppKit/AppKit.h>
#include <QuartzCore/QuartzCore.h>

namespace Lucy
{
    Application CurrentApplication;

    Application::~Application() noexcept
    {
        [((__bridge NSApplication*) m_application) release];
    }

    auto Application::Setup(void* delegate) noexcept -> void
    {
        NSApplication* nsapp = [NSApplication sharedApplication];
        m_application = nsapp;
        [nsapp setDelegate: (__bridge id<NSApplicationDelegate>) delegate];
        [nsapp run];
    }

    auto Application::Init(void* delegate, void* sender) noexcept -> void
    {
        NSWindow* nswindow = [[NSWindow alloc] initWithContentRect: [[NSScreen mainScreen] frame] styleMask: NSWindowStyleMaskResizable | NSWindowStyleMaskClosable | NSWindowStyleMaskTitled | NSWindowStyleMaskMiniaturizable backing: NSBackingStoreBuffered defer: NO];
        m_window = nswindow;
        nswindow.title = [NSString stringWithUTF8String: "Lucy"];
        [nswindow makeKeyAndOrderFront: (__bridge id) sender];
        [nswindow setContentView: [[NSView alloc] init]];
        nswindow.contentView.wantsLayer = YES;
        nswindow.contentView.layer = [CAMetalLayer layer];
        CAMetalLayer* calayer = (CAMetalLayer*)nswindow.contentView.layer;
        id<MTLDevice> mtldevice = MTLCreateSystemDefaultDevice();
        m_device = calayer.device = mtldevice;
        calayer.maximumDrawableCount = 2ull;
        calayer.pixelFormat = MTLPixelFormatBGRA8Unorm;
        calayer.framebufferOnly = NO;
        CAMetalDisplayLink* cadisplay = [[CAMetalDisplayLink alloc] initWithMetalLayer: calayer];
        m_display = cadisplay;
        cadisplay.delegate = (__bridge id<CAMetalDisplayLinkDelegate>) delegate;
        m_library = [mtldevice newDefaultLibrary];
        m_queue = [mtldevice newCommandQueue];
        [cadisplay addToRunLoop: [NSRunLoop currentRunLoop] forMode: NSRunLoopCommonModes];
    }

    auto Application::Update(void* drawable) noexcept -> void
    {
        id<CAMetalDrawable> computeDrawable = (__bridge id<CAMetalDrawable>) drawable;
        id<MTLCommandQueue> commandQueue = (__bridge id<MTLCommandQueue>) m_queue;
        id<MTLCommandBuffer> commandBuffer = [commandQueue commandBuffer];
        id<MTLComputeCommandEncoder> computeEncoder = [commandBuffer computeCommandEncoder];
        const char* name = "Render";
        id<MTLComputePipelineState> compute = [((__bridge id<MTLDevice>) m_device) newComputePipelineStateWithFunction: [((__bridge id<MTLLibrary>) m_library) newFunctionWithName: [NSString stringWithUTF8String: name]] error: nil];
        [computeEncoder setComputePipelineState: compute];
        [computeEncoder setTexture: computeDrawable.texture atIndex: 0];
        MTLSize threadGroupSize = MTLSizeMake(16, 16, 1);
        MTLSize threadGroups = MTLSizeMake((computeDrawable.texture.width + threadGroupSize.width - 1) / threadGroupSize.width, (computeDrawable.texture.height + threadGroupSize.height - 1) / threadGroupSize.height, 1);
        [computeEncoder dispatchThreadgroups: threadGroups threadsPerThreadgroup: threadGroupSize];
        [computeEncoder endEncoding];
        [commandBuffer presentDrawable: computeDrawable];
        [commandBuffer commit];
    }

    auto Application::Finish() noexcept -> void
    {}
}