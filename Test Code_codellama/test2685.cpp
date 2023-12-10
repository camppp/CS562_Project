switch (ev.type) {
    case sf::Event::Closed:
        // Close the application window
        m_window.close();
        break;
    case sf::Event::Resized:
        // Update the UI view to match the new window size
        m_curState->handleEvent(ev);
        break;
    default:
        m_curState->handleEvent(ev);
        break;
}
