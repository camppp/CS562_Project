#include <windows.h>
#include <iostream>

double GetProcessCpuUsage(DWORD processId) {
    FILETIME ftSysIdle, ftSysKernel, ftSysUser;
    FILETIME ftProcCreation, ftProcExit, ftProcKernel, ftProcUser;

    if (!GetSystemTimes(&ftSysIdle, &ftSysKernel, &ftSysUser) ||
        !GetProcessTimes(OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId), &ftProcCreation, &ftProcExit, &ftProcKernel, &ftProcUser)) {
        return -1.0; // Error occurred, return -1 as indication
    }

    ULARGE_INTEGER sysKernelTime, sysUserTime, procKernelTime, procUserTime;
    sysKernelTime.LowPart = ftSysKernel.dwLowDateTime;
    sysKernelTime.HighPart = ftSysKernel.dwHighDateTime;
    sysUserTime.LowPart = ftSysUser.dwLowDateTime;
    sysUserTime.HighPart = ftSysUser.dwHighDateTime;
    procKernelTime.LowPart = ftProcKernel.dwLowDateTime;
    procKernelTime.HighPart = ftProcKernel.dwHighDateTime;
    procUserTime.LowPart = ftProcUser.dwLowDateTime;
    procUserTime.HighPart = ftProcUser.dwHighDateTime;

    ULONGLONG sysKernelTime64 = sysKernelTime.QuadPart;
    ULONGLONG sysUserTime64 = sysUserTime.QuadPart;
    ULONGLONG procKernelTime64 = procKernelTime.QuadPart;
    ULONGLONG procUserTime64 = procUserTime.QuadPart;

    ULONGLONG sysTotalTime = sysKernelTime64 + sysUserTime64;
    ULONGLONG procTotalTime = procKernelTime64 + procUserTime64;

    double cpuUsage = 100.0 * (static_cast<double>(procTotalTime) / static_cast<double>(sysTotalTime));
    return cpuUsage;
}

int main() {
    DWORD processId = 1234; // Replace with the actual process ID
    double cpuUsage = GetProcessCpuUsage(processId);
    if (cpuUsage >= 0.0) {
        std::cout << "CPU Usage: " << cpuUsage << "%" << std::endl;
    } else {
        std::cerr << "Failed to retrieve CPU usage." << std::endl;
    }
    return 0;
}
