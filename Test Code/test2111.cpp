LRESULT CALLBACK CustomWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CREATE:
            // Perform initialization tasks when the window is created
            // ...
            break;
        case WM_COMMAND:
            // Handle commands from controls or menus
            // ...
            break;
        case WM_DESTROY:
            // Clean up resources and perform necessary cleanup when the window is being destroyed
            // ...
            break;
        default:
            // Call the default window procedure for any unhandled messages
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
