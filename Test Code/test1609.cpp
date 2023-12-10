std::wstring Renderer::GetBinPath(std::wstring shader_file) const {
    WCHAR buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    if (pos != std::wstring::npos) {
        return std::wstring(buffer).substr(0, pos + 1);
    }
    return L"";
}
