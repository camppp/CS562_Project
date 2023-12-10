#include <iostream>
#include <cupti.h>

#define ALLOW_ERROR(error, allowed_error) \
    if (error != allowed_error) { \
        LogAndDisableIfError(error); \
        return error; \
    }

#define LOG_AND_DISABLE_IF_ERROR(error) \
    if (error != CUPTI_SUCCESS) { \
        std::cout << "CUPTI Error: " << error << std::endl; \
        DisableErrorLogging(); \
    }

#define IGNORE_CALL_IF_DISABLED \
    if (error_logging_enabled_ == false) { \
        return CUPTI_SUCCESS; \
    }

class CuptiErrorManager {
public:
    CUptiResult EventGroupDisable(CUpti_EventGroup event_group) {
        IGNORE_CALL_IF_DISABLED;
        CUptiResult error = interface_->EventGroupDisable(event_group);
        LOG_AND_DISABLE_IF_ERROR(error);
        return error;
    }

    void AllowError(CUptiResult error, CUptiResult allowed_error) {
        if (error != allowed_error) {
            LogAndDisableIfError(error);
        }
    }

    void LogAndDisableIfError(CUptiResult error) {
        if (error != CUPTI_SUCCESS) {
            std::cout << "CUPTI Error: " << error << std::endl;
            DisableErrorLogging();
        }
    }

private:
    bool error_logging_enabled_ = true;

    void DisableErrorLogging() {
        error_logging_enabled_ = false;
    }
};
