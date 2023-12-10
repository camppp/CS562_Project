void checkReturnKey(InputSystem* input, bool& iteration) {
    if (input->isDown(VK_RETURN)) {
        iteration = true;
    } else {
        iteration = false;
    }
}
