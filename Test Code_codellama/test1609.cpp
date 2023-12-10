#include <iostream>
#include <string>
#include <windows.h>
#include <shlwapi.h>

class Renderer {
public:
    std::wstring GetBinPath(std::wstring shader_file) const;
};

std::wstring Renderer::GetBinPath(std::wstring shader_file) const {
    WCHAR buffer[MAX_PATH];
    // Retrieve the directory path of the specified shader file and store it in the buffer
    PathFindOnPathW(buffer, shader_file.c_str(), MAX_PATH);
    // Return the directory path as a std::wstring
    return std::wstring(buffer);
}

int main() {
    Renderer renderer;
    std::wstring shaderFile = L"example_shader.fx";
    std::wstring binPath = renderer.GetBinPath(shaderFile);
    std::wcout << L"The directory path of " << shaderFile << L" is: " << binPath << std::endl;
    return 0;
}
