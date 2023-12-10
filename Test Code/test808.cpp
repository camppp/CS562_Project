LRESULT CALLBACK TopWindowProc(int code, WPARAM wparam, LPARAM lparam) {
  CWPSTRUCT* info = reinterpret_cast<CWPSTRUCT*>(lparam);
  const UINT &message = info->message;
  const HWND &message_hwnd = info->hwnd;

  if (message == WM_MOVE) {
    // Handle WM_MOVE message
    // Notify appropriate Chrome-Frame instances
    // Your implementation here
  } else if (message == WM_MOVING) {
    // Handle WM_MOVING message
    // Notify appropriate Chrome-Frame instances
    // Your implementation here
  }

  // Perform default processing for other messages
  return CallNextHookEx(NULL, code, wparam, lparam);
}
