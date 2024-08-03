#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#include "Signal.hpp"
#include <signal.h>

namespace Lucy
{
    auto Signal(Action action, Default) noexcept -> void
    {
        int value = SIGTERM;
        switch(action)
        {
            using enum Action;
            case Abort:
                value = SIGABRT;
            break;
            case UnknownInstruction:
                value = SIGILL;
            break;
            case Interruptor:
                value = SIGINT;
            break;
            case Segfault:
                value = SIGSEGV;
            break;
            case Termination:
            break;
        }
        signal(value, SIG_DFL);
    }

    auto Signal(Action action, Ignore) noexcept -> void
    {
        int value = SIGTERM;
        switch(action)
        {
            using enum Action;
            case Abort:
                value = SIGABRT;
            break;
            case UnknownInstruction:
                value = SIGILL;
            break;
            case Interruptor:
                value = SIGINT;
            break;
            case Segfault:
                value = SIGSEGV;
            break;
            case Termination:
            break;
        }
        signal(value, SIG_IGN);
    }

    auto Signal(Action action, void (*handler)(int)) noexcept -> void
    {
        int value = SIGTERM;
        switch(action)
        {
            using enum Action;
            case Abort:
                value = SIGABRT;
            break;
            case UnknownInstruction:
                value = SIGILL;
            break;
            case Interruptor:
                value = SIGINT;
            break;
            case Segfault:
                value = SIGSEGV;
            break;
            case Termination:
            break;
        }
        signal(value, handler);
    }
}

#endif