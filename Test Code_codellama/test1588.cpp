class SystemStatus {
private:
    bool m_setupFailed;
    int m_shuttingDown;
    bool m_startFailed;

    bool m_setupFailedHasBeenSet;
    bool m_shuttingDownHasBeenSet;
    bool m_startFailedHasBeenSet;

public:
    SystemStatus() : m_setupFailed(false), m_shuttingDown(0), m_startFailed(false),
                      m_setupFailedHasBeenSet(false), m_shuttingDownHasBeenSet(false),
                      m_startFailedHasBeenSet(false) {}

    void ProcessStatusJson(const json& jsonObject) {
        for (auto& [key, value] : jsonObject.items()) {
            if (key == "setupFailed") {
                m_setupFailed = value.get<bool>();
                m_setupFailedHasBeenSet = true;
            } else if (key == "shuttingDown") {
                m_shuttingDown = value.get<int>();
                m_shuttingDownHasBeenSet = true;
            } else if (key == "startFailed") {
                m_startFailed = value.get<bool>();
                m_startFailedHasBeenSet = true;
            }
        }
    }

    bool GetSetupFailed() {
        return m_setupFailed;
    }

    bool GetShuttingDown() {
        return m_shuttingDown;
    }

    bool GetStartFailed() {
        return m_startFailed;
    }
};
