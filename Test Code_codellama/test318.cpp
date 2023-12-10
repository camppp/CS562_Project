void HTMLAnchorElement::setActive(bool down, bool pause) {
  // Check if the element has an editable style
  if (hasEditableStyle()) {
    // If the mouse button is pressed and the shift key is not pressed,
    // set the element's active state to true
    if (down && !pause && !event.shiftKey) {
      setActive(true);
    }

    // If the mouse button is released and the shift key is not pressed,
    // set the element's active state to false
    if (!down && !pause && !event.shiftKey) {
      setActive(false);
    }

    // If the mouse button is pressed and the shift key is pressed,
    // set the element's active state to true and pause the action
    if (down && pause && event.shiftKey) {
      setActive(true);
      pauseAction();
    }

    // If the mouse button is released and the shift key is pressed,
    // set the element's active state to false and resume the action
    if (!down && pause && event.shiftKey) {
      setActive(false);
      resumeAction();
    }
  }
}
