class TimeManager
{
public:
    TimeManager();
    ~TimeManager();

    void SetScaleDir(float scale);
    void SetTicksPerSec(double ticks);
    void EnableTimeFunction();
    void DisableTimeFunction();

    LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
    float scaleDir;
    double ticksPerSec;
    bool timeFunction;
};

TimeManager::TimeManager()
{
    scaleDir = 1.0f;
    ticksPerSec = 1000.0;
    timeFunction = false;
}

TimeManager::~TimeManager()
{
}

void TimeManager::SetScaleDir(float scale)
{
    scaleDir = scale;
}

void TimeManager::SetTicksPerSec(double ticks)
{
    ticksPerSec = ticks;
}

void TimeManager::EnableTimeFunction()
{
    timeFunction = true;
}

void TimeManager::DisableTimeFunction()
{
    timeFunction = false;
}

LRESULT TimeManager::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_TIMER:
            // Handle timer message
            break;
        case WM_PAINT:
            // Handle paint message
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
