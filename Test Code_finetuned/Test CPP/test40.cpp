size_t File::GetSize() const
{
    if (_file->IsWriting())
    {
        throw std::logic_error("File is currently being written to");
    }

    std::shared_ptr<Ftp::FileReadable> file(_ftpSessionHandle->OpenFile(_path, Ftp::FileMode::Read));
    return file->GetSize();
}