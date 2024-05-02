module;
#ifdef lucy_windows
#include <Windows.h>
#endif
export module Lucy.Core.Exit;
import Lucy.Core.Abort;

export [[noreturn]] auto Exit() noexcept -> void
{
    #ifdef lucy_windows
    DWORD exitcode;
    if(not GetExitCodeProcess(GetCurrentProcess(), &exitcode))
        Abort();
    ExitProcess(exitcode);
    #endif
}