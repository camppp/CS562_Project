LRESULT CALLBACK TopWindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message)
    {
        case WM_MOVE:
        {
            // Handle the WM_MOVE message
            // ...
            break;
        }
        case WM_MOVING:
        {
            // Handle the WM_MOVING message
            // ...
            break;
        }
        default:
        {
            // Pass the message to the default window procedure
            return DefWindowProc(hwnd, message, wparam, lparam);
        }
    }

    return 0;
}
