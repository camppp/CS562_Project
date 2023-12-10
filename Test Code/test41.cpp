#include <memory>
#include <stdexcept>

namespace Ftp {
    class FileWritable {
        // Implementation for writing files in FTP session
    };

    class FileReadable {
    public:
        FileReadable(FtpSessionHandle handle, const char* path) {
            // Implementation for reading files in FTP session
        }

        ::File::Size GetSize() {
            // Implementation to retrieve file size from FTP session
        }
    };
}

class File {
private:
    std::unique_ptr<Ftp::FileWritable> _file;
    FtpSessionHandle _ftpSessionHandle;
    const char* _path;

public:
    using Size = long long; // Assuming file size is represented as a long long

    File(FtpSessionHandle handle, const char* path) : _ftpSessionHandle(handle), _path(path) {
        // Constructor implementation
    }

    Size GetSize() {
        if (_file.get() != nullptr) {
            throw std::logic_error("Ftp::File::GetSize called during transfer");
        }

        Ftp::FileReadable file(_ftpSessionHandle, _path);
        return file.GetSize();
    }
};
