std::wstring GetFileExtension(const std::wstring& filename)
{
    // Find the last dot ('.') character in the filename
    size_t dot_pos = filename.find_last_of('.');

    // If there is no dot character, return an empty string
    if (dot_pos == std::wstring::npos)
        return L"";

    // Return the substring of the filename starting from the dot character
    return filename.substr(dot_pos + 1);
}
