auto kawe::EventProvider::getNextEvent() -> event::Event
{
    if (!m_events_processed.empty()) {
        auto nextEvent = m_events_processed.back();
        m_events_processed.pop_back();
        return nextEvent;
    } else {
        return fetchEvent();
    }
}
