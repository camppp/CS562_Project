#include <windows.h>
#include <iostream>

double GetProcessCpuUsage(DWORD processId) {
    FILETIME creationTime, exitTime, kernelTime, userTime;
    if (!GetProcessTimes(processId, &creationTime, &exitTime, &kernelTime, &userTime)) {
        return 0.0; // Return 0 if the function fails
    }

    ULARGE_INTEGER systemTime, processTime;
    systemTime.HighPart = kernelTime.dwHighDateTime;
    systemTime.LowPart = kernelTime.dwLowDateTime;
    processTime.HighPart = userTime.dwHighDateTime;
    processTime.LowPart = userTime.dwLowDateTime;

    ULONGLONG totalSystemTime = systemTime.QuadPart;
    ULONGLONG totalProcessTime = processTime.QuadPart;

    ULONGLONG totalTime = totalSystemTime + totalProcessTime;
    if (totalTime == 0) {
        return 0.0; // Return 0 if the total time is 0
    }

    double cpuUsage = (double)totalProcessTime / (double)totalTime * 100.0;
    return cpuUsage;
}
