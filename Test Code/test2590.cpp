#include <Windows.h>
#include <string>

class RegistryLogger {
public:
    bool AppendLogFilePath(const base::FilePath& log_file) {
        // Check if the logging key is valid
        if (!logging_key_.IsValid()) {
            return false;
        }

        // Convert the log file path to a string
        std::wstring log_file_str = log_file.value();

        // Append the log file path to the registry key
        LSTATUS status = RegSetValueEx(logging_key_.Handle(), L"LogFilePath", 0, REG_SZ, (BYTE*)log_file_str.c_str(), (log_file_str.size() + 1) * sizeof(wchar_t));

        // Check if the append operation was successful
        if (status != ERROR_SUCCESS) {
            return false;
        }

        return true;
    }

private:
    base::FilePath logging_key_;
};
