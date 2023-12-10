#include <Windows.h>

class c_file_open_dlg {
public:
    c_file_open_dlg();
    ~c_file_open_dlg();

    void do_modal();

private:
    HWND hwnd;
    OPENFILENAME ofn;
    TCHAR szFile[MAX_PATH];
};

c_file_open_dlg::c_file_open_dlg() {
    // Initialize member variables
    hwnd = NULL;
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = NULL;
    ofn.hInstance = NULL;
    ofn.lpstrFilter = NULL;
    ofn.lpstrCustomFilter = NULL;
    ofn.nMaxCustFilter = 0;
    ofn.nFilterIndex = 1;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_ENABLESIZING | OFN_EXPLORER | OFN_FILEMUSTEXIST;
}

c_file_open_dlg::~c_file_open_dlg() {
    // Release resources
    if (hwnd) {
        DestroyWindow(hwnd);
    }
}

void c_file_open_dlg::do_modal() {
    // Display the file open dialog window
    hwnd = CreateFileDialog(NULL, NULL, NULL, NULL, NULL, OFN_ENABLESIZING | OFN_EXPLORER | OFN_FILEMUSTEXIST, szFile, MAX_PATH);
    if (hwnd) {
        // Show the dialog window
        ShowWindow(hwnd, SW_SHOW);
        // Wait for the user to select a file
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            if (!IsDialogMessage(hwnd, &msg)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        // Get the selected file's path
        GetOpenFileName(&ofn);
        // Close the dialog window
        DestroyWindow(hwnd);
    }
}
