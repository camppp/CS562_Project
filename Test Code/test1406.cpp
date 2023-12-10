#include <vector>

namespace kawe {
    namespace event {
        struct Event {
            // Event structure details
        };
    }

    class EventProvider {
    public:
        event::Event getNextEvent() {
            if (!m_events_processed.empty()) {
                return m_events_processed.front();
            } else {
                return fetchEvent();
            }
        }

    private:
        event::Event fetchEvent();
        std::vector<event::Event> m_events_processed;
    };
}
