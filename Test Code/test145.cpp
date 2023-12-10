#include <windows.h>  // Assuming Windows platform for timer functionality

class DPC {
public:
    using FunctionType = void(*)(void*);

    DPC(FunctionType function, void* context) : function_(function), context_(context), timerId_(0) {}

    void SetTimer(unsigned int delayMs) {
        timerId_ = SetTimer(NULL, 0, delayMs, TimerProc);
    }

    void Cancel() {
        if (timerId_ != 0) {
            KillTimer(NULL, timerId_);
            timerId_ = 0;
        }
    }

    ~DPC() {
        Cancel();
    }

private:
    static void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
        DPC* dpc = reinterpret_cast<DPC*>(idEvent);
        dpc->function_(dpc->context_);
    }

    FunctionType function_;
    void* context_;
    UINT_PTR timerId_;
};
