#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifdef lucy_mac
#include "Core/Application.hpp"
#include <AppKit/AppKit.h>
#include <QuartzCore/QuartzCore.h>

@interface LucyAppRenderer : NSObject<CAMetalDisplayLinkDelegate>
@end

@implementation LucyAppRenderer

- (void)metalDisplayLink:(nonnull CAMetalDisplayLink*) link needsUpdate:(nonnull CAMetalDisplayLinkUpdate*) update
{
    ::Lucy::CurrentApplication.Update(update.drawable);
}

@end

@interface LucyAppDel : NSObject<NSApplicationDelegate, NSWindowDelegate>{}
@end
@implementation LucyAppDel
-(id)init
{
    if (self = [super init])
        ::Lucy::CurrentApplication.Init([[LucyAppRenderer alloc] init], self);
    return self;
}

-(BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*) sender
{
    return YES;
}

-(void)applicationWillTerminate:(NSNotification*)notification
{
    ::Lucy::CurrentApplication.Finish();
}
@end

int main()
{
    ::Lucy::CurrentApplication.Setup([[LucyAppDel alloc] init]);
}

#endif
#endif