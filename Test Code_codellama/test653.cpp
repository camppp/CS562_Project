void Direct3DInterop::OnPointerReleased(DrawingSurfaceManipulationHost^ sender, PointerEventArgs^ args)
{
    // Get the pointer ID and position
    uint32_t pointerId = args->PointerId;
    Windows::Foundation::Point pointerPosition = args->CurrentPoint->Position;

    // Check if the pointer is over the drawing surface
    bool isOverSurface = sender->IsPointerOver(pointerId);

    // If the pointer is over the surface, handle the pointer release event
    if (isOverSurface)
    {
        // Get the pointer properties
        Windows::UI::Input::PointerPoint^ pointerPoint = sender->GetPointerPoint(pointerId);
        Windows::UI::Input::PointerDeviceType pointerDeviceType = pointerPoint->PointerDeviceType;

        // Handle the pointer release event
        if (pointerDeviceType == Windows::UI::Input::PointerDeviceType::Touch)
        {
            // Handle touch pointer release event
            HandleTouchPointerRelease(pointerId, pointerPosition);
        }
        else if (pointerDeviceType == Windows::UI::Input::PointerDeviceType::Pen)
        {
            // Handle pen pointer release event
            HandlePenPointerRelease(pointerId, pointerPosition);
        }
        else if (pointerDeviceType == Windows::UI::Input::PointerDeviceType::Mouse)
        {
            // Handle mouse pointer release event
            HandleMousePointerRelease(pointerId, pointerPosition);
        }
    }
}
