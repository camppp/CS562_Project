#include <Windows.h>

class UserInterface {
public:
    void Initialize(HINSTANCE hInstance) {
        // Perform UI framework initialization using the provided instance handle
        // Example: Register window class, initialize resources, etc.
    }

    void InitMainWindow() {
        // Set up the main application window
        // Example: Create window, set properties, register event handlers, etc.
    }

    int MessageLoop() {
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return static_cast<int>(msg.wParam);
    }
};

UserInterface* pUi = new UserInterface();

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
    pUi->Initialize(hInstance);
    pUi->InitMainWindow();
    return pUi->MessageLoop();
}
