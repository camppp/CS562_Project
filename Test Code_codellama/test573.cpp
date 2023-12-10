class context_guard {
public:
    context_guard(WindowSystem& window_system, Window& window)
        : window_system_(window_system), window_(window) {
        if (!window_system_.windowStillExists(window_.handle)) {
            log::warn("Window no longer exists, clearing rendering context");
            window_system_.makeContextCurrent(nullptr);
        } else {
            window_system_.makeContextCurrent(window_);
        }
    }

    ~context_guard() {
        if (window_system_.windowStillExists(window_.handle)) {
            window_system_.makeContextCurrent(nullptr);
        }
    }

private:
    WindowSystem& window_system_;
    Window& window_;
};
