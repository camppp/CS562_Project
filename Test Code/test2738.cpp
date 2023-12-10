#include <windows.h>

class c_file_open_dlg {
private:
    OPENFILENAME _ofn; // Structure to hold the file open dialog information
    TCHAR _szFile[MAX_PATH]; // Buffer to store the selected file's path

public:
    c_file_open_dlg() {
        ZeroMemory(&_ofn, sizeof(_ofn)); // Initialize the OPENFILENAME structure
        _ofn.lStructSize = sizeof(_ofn);
        _ofn.hwndOwner = NULL; // Set the owner window handle to NULL
        _ofn.lpstrFile = _szFile; // Set the buffer to store the selected file's path
        _ofn.nMaxFile = MAX_PATH; // Set the maximum length of the file path buffer
        _ofn.Flags = OFN_ENABLESIZING | OFN_EXPLORER | OFN_FILEMUSTEXIST;
    }

    bool do_modal(HWND hOwner) {
        _ofn.hwndOwner = hOwner; // Set the owner window handle
        if (GetOpenFileName(&_ofn)) { // Display the file open dialog and retrieve the selected file's path
            // The selected file's path is stored in _szFile
            return true; // Return true if a file is selected
        }
        return false; // Return false if the dialog is canceled or an error occurs
    }
};

// Example usage
int main() {
    c_file_open_dlg fileDlg;
    HWND hOwner = GetConsoleWindow(); // Get the handle of the console window as the owner
    if (fileDlg.do_modal(hOwner)) {
        // Process the selected file's path
        MessageBox(NULL, fileDlg._szFile, TEXT("Selected File"), MB_OK); // Display the selected file's path
    }
    return 0;
}
