#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_application
#define lucy_core_application

namespace Lucy
{
    class [[nodiscard]] Application final
    {
        #ifdef lucy_mac
        void* m_application, *m_window, *m_device, *m_display, *m_library, *m_queue;
        #endif
    public:
        ~Application() noexcept;

        Application() noexcept = default;

        Application(const Application& other) noexcept = delete;

        Application(Application&& other) noexcept = delete;

        auto operator=(const Application& other) noexcept -> Application& = default;

        auto operator=(Application&& other) noexcept -> Application& = default;

        auto Setup(void* delegate) noexcept -> void;

        auto Init(void* delegate, void* sender) noexcept -> void;

        auto Update(void* drawable) noexcept -> void;

        auto Finish() noexcept -> void;
    };

    extern Application CurrentApplication;
}

#endif
#endif