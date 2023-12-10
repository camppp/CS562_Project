#include <vector>

// Container to hold the received input events
std::vector<scenic::Event> received_input_events;

// Function to inject a fresh event into the rendering session
void InjectFreshEvent(scenic::Session& session, uint32_t compositor_id) {
  // Create a new event with the specified compositor ID
  scenic::Event event;
  event.compositor_id = compositor_id;

  // Add the event to the received input events container
  received_input_events.push_back(event);

  // Trigger the rendering system to present the rendered content
  BlockingPresent(session);

  // Clear the received input events container after presenting the content
  received_input_events.clear();
}
