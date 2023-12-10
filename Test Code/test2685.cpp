switch (ev.type)
{
    case sf::Event::Closed:
        // Close the application window
        m_window.close();
        break;
    case sf::Event::Resized:
        // Update the UI view to match the new window size
        m_uiView.setSize(sf::Vector2f(m_window.getSize()));
        m_uiView.setCenter(m_uiView.getSize() / 2.f);
        break;
    // Add additional cases for other event types if needed
}
