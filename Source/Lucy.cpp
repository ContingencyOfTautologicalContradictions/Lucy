#ifdef lucy_windows
#include <d3d12.h>
#include <dxgi1_6.h>
#ifdef lucy_debug
#include <dxgidebug.h>
#endif
#include <Windows.h>
import Lucy.Core.Exit;
import Lucy.Core.Abort;

#ifdef lucy_debug
IDXGIDebug1* debug;

IDXGIInfoQueue* info;

ID3D12Debug6* ddebug;

ID3D12DebugDevice1* ddevice;
#endif
IDXGIFactory7* factory;

IDXGIAdapter4* adapter;

IDXGIOutput6* output = nullptr;

DXGI_MODE_DESC1 best;

IDXGISwapChain4* swapchain;

ID3D12Device10* device;

ID3D12CommandQueue* queue;

ID3D12DescriptorHeap* heap;

ID3D12Resource2* backbuffers[2];

ID3D12CommandAllocator* allocator;

ID3D12GraphicsCommandList7* graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            #ifdef lucy_debug
            if(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&debug)) not_eq S_OK)
                Abort();
            if(debug->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_ALL)
            not_eq S_OK)
                Abort();
            debug->EnableLeakTrackingForThread();
            if(not debug->IsLeakTrackingEnabledForThread())
                Abort();
            if(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&info)) not_eq S_OK)
                Abort();
            #endif
            if(CreateDXGIFactory2(
            #ifdef lucy_debug
            DXGI_CREATE_FACTORY_DEBUG
            #else
            0
            #endif
            , IID_PPV_ARGS(&factory)) == S_OK)
            {
            if(factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER) == S_OK)
            {
                UINT index = 0;
                while(not adapter)
                {
                    const HRESULT resultadapter = factory->
                    EnumAdapterByGpuPreference(index,
                    DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter
                    ));
                    if(resultadapter == DXGI_ERROR_NOT_FOUND)
                        break;
                    else if(resultadapter not_eq S_OK)
                        ++index;
                    else
                        index = 0;
                }
                if(not adapter)
                    if(factory->EnumWarpAdapter(IID_PPV_ARGS(&adapter)) not_eq
                    S_OK)
                        Abort();
                {
                    HRESULT resultoutput;
                    IDXGIOutput* bestoutput;
                    while((resultoutput = adapter->EnumOutputs(index++, &
                    bestoutput)) == S_OK)
                    {
                        DXGI_OUTPUT_DESC1 outputdesc;
                        if(static_cast<IDXGIOutput6*>(bestoutput)->GetDesc1(&outputdesc) == S_OK)
                            if(outputdesc.ColorSpace == DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020)
                            {
                                UINT supported = 0;
                                if(static_cast<IDXGIOutput6*>(bestoutput)->
                                GetDisplayModeList1(DXGI_FORMAT_R10G10B10A2_UNORM, 0, &
                                supported, 0) == S_OK)
                                    if(supported)
                                    {
                                        DXGI_MODE_DESC1* desc = new DXGI_MODE_DESC1[
                                        supported];
                                        if(static_cast<IDXGIOutput6*>(bestoutput)->
                                        GetDisplayModeList1(
                                        DXGI_FORMAT_R10G10B10A2_UNORM, 0, &supported,
                                        desc) == S_OK)
                                            for(UINT x = 0; x < supported; ++x)
                                            {
                                                const DXGI_MODE_DESC1& adesc = desc[x];
                                                if(adesc.RefreshRate.Numerator > 1 and
                                                adesc.RefreshRate.Denominator == 1)
                                                    if(adesc.Width > best.Width and
                                                    adesc.Height > best.Height and
                                                    adesc.RefreshRate.Numerator > best.
                                                    RefreshRate.Numerator)
                                                    {
                                                        best = adesc;
                                                        output = static_cast<
                                                        IDXGIOutput6*>(bestoutput);
                                                    }
                                            }
                                        delete[] desc;
                                    }
                            }
                    }
                    if(output not_eq nullptr)
                    {
                        index = 0;
                        while((resultoutput = adapter->EnumOutputs(index++, &
                        bestoutput)) == S_OK)
                        {
                            UINT supported = 0;
                            if(static_cast<IDXGIOutput6*>(bestoutput)->
                            GetDisplayModeList1(DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
                            , 0, &supported, 0) == S_OK)
                                if(supported)
                                {
                                    DXGI_MODE_DESC1* desc = new DXGI_MODE_DESC1
                                    [supported];
                                    if(static_cast<IDXGIOutput6*>(bestoutput)->
                                    GetDisplayModeList1(
                                    DXGI_FORMAT_R8G8B8A8_UNORM_SRGB, 0, &
                                    supported, desc) == S_OK)
                                        for(UINT x = 0; x < supported; ++x)
                                        {
                                            const DXGI_MODE_DESC1& adesc = desc
                                            [x];
                                            if(adesc.RefreshRate.Numerator > 1
                                            and adesc.RefreshRate.Denominator
                                            == 1)
                                                if(adesc.Width > best.Width and
                                                adesc.Height > best.Height and
                                                adesc.RefreshRate.Numerator >
                                                best.RefreshRate.Numerator)
                                                {
                                                    best = adesc;
                                                    output = static_cast<
                                                    IDXGIOutput6*>(bestoutput);
                                                }
                                        }
                                    delete[] desc;
                                }
                        }
                    }
                }
                if(output)
                {
                    #ifdef lucy_debug
                    if(D3D12GetDebugInterface(IID_PPV_ARGS(&ddebug)) not_eq
                    S_OK)
                        Abort();
                    ddebug->EnableDebugLayer();
                    ddebug->SetForceLegacyBarrierValidation(true);
                    ddebug->SetEnableAutoName(true);
                    ddebug->SetGPUBasedValidationFlags(
                    D3D12_GPU_BASED_VALIDATION_FLAGS_NONE);
                    ddebug->SetEnableSynchronizedCommandQueueValidation(true);
                    ddebug->SetEnableGPUBasedValidation(true);
                    #endif
                    if(D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_12_2,
                    IID_PPV_ARGS(&device)) == S_OK)
                    {
                        if(device->QueryInterface(IID_PPV_ARGS(&ddevice)) ==
                        S_OK)
                        {
                            if(ddevice->ReportLiveDeviceObjects(
                            D3D12_RLDO_DETAIL) == S_OK)
                            {
                                D3D12_COMMAND_QUEUE_DESC queue_desc;
                                queue_desc.Type =
                                D3D12_COMMAND_LIST_TYPE_DIRECT;
                                queue_desc.Priority =
                                D3D12_COMMAND_QUEUE_PRIORITY_HIGH;
                                queue_desc.Flags =
                                D3D12_COMMAND_QUEUE_FLAG_NONE;
                                queue_desc.NodeMask = 0;
                                if(device->CreateCommandQueue(&queue_desc,
                                IID_PPV_ARGS(&queue)) == S_OK)
                                {
                                    {
                                        DXGI_SWAP_CHAIN_DESC1 swapdesc;
                                        swapdesc.Width = best.Width;
                                        swapdesc.Height = best.Height;
                                        swapdesc.Format = best.Format;
                                        swapdesc.Stereo = best.Stereo;
                                        DXGI_SAMPLE_DESC swapsample;
                                        swapsample.Count = 1;
                                        swapsample.Quality = 0;
                                        swapdesc.SampleDesc = swapsample;
                                        swapdesc.BufferUsage =
                                        DXGI_USAGE_BACK_BUFFER bitor
                                        DXGI_USAGE_RENDER_TARGET_OUTPUT;
                                        swapdesc.BufferCount = 2;
                                        swapdesc.Scaling = DXGI_SCALING_STRETCH
                                        ;
                                        swapdesc.SwapEffect =
                                        DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
                                        swapdesc.AlphaMode =
                                        DXGI_ALPHA_MODE_IGNORE;
                                        swapdesc.Flags =
                                        DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH
                                        bitor
                                        DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING;
                                        DXGI_SWAP_CHAIN_FULLSCREEN_DESC
                                        swapfulldesc;
                                        swapfulldesc.RefreshRate = best.
                                        RefreshRate;
                                        swapfulldesc.ScanlineOrdering = best.
                                        ScanlineOrdering;
                                        swapfulldesc.Scaling = best.Scaling;
                                        swapfulldesc.Windowed = true; // temporary
                                        IDXGISwapChain1* oldswapchain;
                                        if(factory->CreateSwapChainForHwnd(
                                        queue, hwnd, &swapdesc, &swapfulldesc,
                                        output, &oldswapchain) == S_OK)
                                            swapchain = static_cast<
                                            IDXGISwapChain4*>(oldswapchain);
                                        else
                                            Abort();
                                    }
                                    D3D12_DESCRIPTOR_HEAP_DESC heapdesc;
                                    heapdesc.Type =
                                    D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
                                    heapdesc.NumDescriptors = 2;
                                    heapdesc.Flags =
                                    D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
                                    heapdesc.NodeMask = 0;
                                    if(device->CreateDescriptorHeap(&heapdesc,
                                    IID_PPV_ARGS(&heap)) == S_OK)
                                    {
                                        ID3D12Resource* oldbackbuffers[2];
                                        if(swapchain->GetBuffer(0, IID_PPV_ARGS
                                        (&oldbackbuffers[0])) == S_OK)
                                        {
                                            D3D12_CPU_DESCRIPTOR_HANDLE
                                            heapoffset = heap->
                                            GetCPUDescriptorHandleForHeapStart(
                                            );
                                            device->CreateRenderTargetView(
                                            oldbackbuffers[0], 0, heapoffset);
                                            backbuffers[0] = static_cast<
                                            ID3D12Resource2*>(oldbackbuffers[0]
                                            );
                                            heapoffset.ptr += device->
                                            GetDescriptorHandleIncrementSize(
                                            D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
                                            if(swapchain->GetBuffer(1,
                                            IID_PPV_ARGS(&oldbackbuffers[1]))
                                            == S_OK)
                                            {
                                                device->CreateRenderTargetView(
                                                oldbackbuffers[1], 0,
                                                heapoffset);
                                                backbuffers[1] = static_cast<
                                                ID3D12Resource2*>(
                                                oldbackbuffers[1]);
                                                if(device->
                                                CreateCommandAllocator(
                                                D3D12_COMMAND_LIST_TYPE_DIRECT,
                                                IID_PPV_ARGS(&allocator)) ==
                                                S_OK)
                                                {
                                                    if(device->
                                                    CreateCommandList1(0,
                                                    D3D12_COMMAND_LIST_TYPE_DIRECT
                                                    ,
                                                    D3D12_COMMAND_LIST_FLAG_NONE
                                                    , IID_PPV_ARGS(&graphics))
                                                    == S_OK)
                                                    {
                                                        if(graphics->Reset(
                                                        allocator, 0) not_eq
                                                        S_OK)
                                                            Abort();
                                                    }
                                                    else
                                                        Abort();
                                                }
                                                else
                                                    Abort();
                                            }
                                            else
                                                Abort();
                                        }
                                        else
                                            Abort();
                                    }
                                }
                                else
                                    Abort();
                            }
                            else
                                Abort();
                        }
                        else
                            Abort();
                    }
                    else
                        Abort();
                }
                //else
                    //Abort();
            }
            else
                Abort();
            }
            else
                Abort();
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
        case WM_CLOSE:
        {
            graphics->Release();
            allocator->Release();
            backbuffers[1]->Release();
            backbuffers[0]->Release();
            heap->Release();
            swapchain->Release();
            queue->Release();
            ddevice->Release();
            device->Release();
            ddebug->DisableDebugLayer();
            ddebug->Release();
            output->Release();
            adapter->Release();
            factory->Release();
            #ifdef lucy_debug
            info->Release();
            debug->DisableLeakTrackingForThread();
            if(debug->IsLeakTrackingEnabledForThread())
                Abort();
            debug->Release();
            #endif
            if(not DestroyWindow(hwnd))
                Abort();
            HINSTANCE instance;
            if(not GetModuleHandleExW(0, 0, &instance) or not instance)
                Abort();
            if(not UnregisterClassW(L"lucy_private_and_secret_window_class",
            instance))
                Abort();
            Exit();
        }
        break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
    WNDCLASSEXW windowClass;
    windowClass.cbSize = sizeof(WNDCLASSEXW);
    windowClass.style = CS_DBLCLKS bitor CS_HREDRAW bitor CS_OWNDC bitor
    CS_VREDRAW;
    windowClass.lpfnWndProc = WindowProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = instance;
    windowClass.hIcon = 0; // temporary
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW); // temporary
    windowClass.hbrBackground = 0;
    windowClass.lpszMenuName = 0;
    windowClass.lpszClassName = L"lucy_private_and_secret_window_class";
    windowClass.hIconSm = 0; //temporary
    if(RegisterClassExW(&windowClass))
    {
        if(int windowSizeX = GetSystemMetrics(SM_CXSCREEN))
        {
            if(int windowSizeY = GetSystemMetrics(SM_CYSCREEN))
            {
                if(HWND window = CreateWindowExW(WS_EX_APPWINDOW,
                L"lucy_private_and_secret_window_class", L"Lucy",
                WS_OVERLAPPEDWINDOW, 0, 0, windowSizeX, windowSizeY, 0, 0,
                instance, 0))
                {
                    if(not ShowWindow(window, SW_SHOW))
                    {
                        if(UpdateWindow(window))
                        {
                            MSG msg;
                            while(GetMessageW(&msg, window, 0, 0))
                            {
                                TranslateMessage(&msg);
                                DispatchMessageW(&msg);
                            }
                       }
                        else
                            Abort();
                    }
                    else
                        Abort();
                }
                else
                    Abort();
            }
            else
                Abort();
        }
        else
            Abort();
    }
    else
        Abort();
    return 0;
}

#endif