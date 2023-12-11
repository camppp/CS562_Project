#include <Windows.h>

class ApplicationStatusManager {
public:
    ApplicationStatusManager() : mStatus(APP_RUN) {}

    void handleMessage(MSG& msg) {
        switch (msg.message) {
            case WM_QUIT:
                mStatus = APP_QUIT;
                break;
            case WM_PAINT:
                mStatus = APP_RUN;
                break;
            default:
                break;
        }
    }

    int getStatus() {
        return mStatus;
    }

private:
    int mStatus;
};
