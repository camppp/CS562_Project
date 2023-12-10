void onDirectionKey(DIRECTION dir) {
    switch (dir) {
        case UP:
            switch (focus) {
                case StatusFocusOnTabIndex:
                    if (currentTabIndex > 0) {
                        currentTabIndex--;
                        updateDisplay();
                    }
                    break;
                case StatusFocusOnStatus:
                    // Handle UP direction when focus is on status
                    // (Optional based on the specific requirements)
                    break;
            }
            break;
        // Handle other directional key cases (DOWN, LEFT, RIGHT)
        // (Optional based on the specific requirements)
    }
}
