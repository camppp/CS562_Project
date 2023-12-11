#include <windows.h>

bool request_ioctl(int command, Payload* payload, size_t size) {
    HANDLE hDevice = CreateFile(L"\\\\.\\MyDriver", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hDevice == INVALID_HANDLE_VALUE) {
        return false;
    }

    DWORD bytesReturned;
    if (!DeviceIoControl(hDevice, command, payload, size, payload, size, &bytesReturned, NULL)) {
        CloseHandle(hDevice);
        return false;
    }

    CloseHandle(hDevice);
    return true;
}