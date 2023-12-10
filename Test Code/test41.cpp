class File {
private:
    std::unique_ptr<Ftp::FileWritable> _file;
    FtpSessionHandle _ftpSessionHandle;
    std::string _path;

public:
    // ...

    size_t GetSize() {
        // Ensure that the file is not currently being used for writing
        Assume(_file->IsReadable());

        // Create a Ftp::FileReadable object using the FTP session handle and file path
        Ftp::FileReadable fileReadable(_ftpSessionHandle, _path);

        // Retrieve the size of the file
        return fileReadable.GetSize();
    }
};
