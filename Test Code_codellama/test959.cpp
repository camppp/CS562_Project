#include <cuda_runtime.h>
#include <cupti.h>

class CuptiErrorManager {
public:
    // Constructor
    CuptiErrorManager() {
        // Initialize CUPTI
        CUpti_Initialize(0);
    }

    // Destructor
    ~CuptiErrorManager() {
        // Finalize CUPTI
        CUpti_Finalize();
    }

    // Disable an event group
    void EventGroupDisable(CUpti_EventGroup event_group) {
        // Disable the event group
        CUpti_EventGroupDisable(event_group);

        // Check for errors
        CUptiResult error = CUpti_GetResult();
        if (error != CUPTI_SUCCESS) {
            // Log the error
            LogError(error);

            // Disable error logging for this event group
            DisableErrorLogging(event_group);
        }
    }

    // Allow a specific error to occur without triggering the error handling mechanism
    void AllowError(CUptiResult error, CUptiResult allowed_error) {
        // Check if the error is allowed
        if (error == allowed_error) {
            // Allow the error to occur
            CUpti_AllowError(error);
        }
    }

    // Log an error and disable error logging if the error is not allowed
    void LogAndDisableIfError(CUptiResult error) {
        // Check if the error is allowed
        if (error != CUPTI_SUCCESS) {
            // Log the error
            LogError(error);

            // Disable error logging for this event group
            DisableErrorLogging(event_group);
        }
    }

private:
    // Log an error
    void LogError(CUptiResult error) {
        // Log the error message
        printf("Error: %s\n", CUpti_GetErrorString(error));
    }

    // Disable error logging for a specific event group
    void DisableErrorLogging(CUpti_EventGroup event_group) {
        // Disable error logging for the event group
        CUpti_EventGroupDisable(event_group);
    }
};
