#include <iostream>
#include <deque>
#include <vector>
#include <map>

struct Flow {
    // Define the properties and requirements of a network flow
    uint32_t id;
    uint32_t qosLevel;
    // Other flow properties and requirements
};

struct Event {
    // Define the properties of an event, such as flow arrival
    uint64_t timestamp;
    Flow* flow;
    // Other event properties
};

struct AggChannel {
    // Define the properties and capabilities of an aggregated channel
    // e.g., bandwidth, latency, QoS level
};

// Custom comparator for sorting events based on arrival time
struct EventComparator {
    bool operator()(const Event* e1, const Event* e2) const {
        return e1->timestamp > e2->timestamp; // Sort in ascending order of arrival time
    }
};

void scheduleFlows(std::deque<Flow*>& flows_to_schedule, std::deque<Event*>& flow_arrivals, 
                   std::vector<std::map<std::pair<uint32_t, uint32_t>, AggChannel*>>& channels, 
                   std::vector<std::vector<double>>& per_pkt_lat) {
    // Sort the flow arrival events based on arrival time
    std::sort(flow_arrivals.begin(), flow_arrivals.end(), EventComparator());

    // Iterate through the sorted arrival events and schedule the flows
    for (Event* arrivalEvent : flow_arrivals) {
        Flow* flow = arrivalEvent->flow;
        uint32_t qosLevel = flow->qosLevel;

        // Find the available channel with the highest QoS level for the flow
        for (auto it = channels[qosLevel].begin(); it != channels[qosLevel].end(); ++it) {
            // Check if the channel satisfies the flow's requirements
            if (/* Check channel availability and other constraints */) {
                // Schedule the flow on the selected channel
                // Update per-packet latency and other relevant data structures
                break; // Break after scheduling the flow on the first suitable channel
            }
        }
    }
}

int main() {
    // Sample usage of the scheduling algorithm
    std::deque<Flow*> flows_to_schedule;
    std::deque<Event*> flow_arrivals;
    std::vector<std::map<std::pair<uint32_t, uint32_t>, AggChannel*>> channels;
    std::vector<std::vector<double>> per_pkt_lat;

    // Populate flows_to_schedule, flow_arrivals, channels, and per_pkt_lat with sample data

    // Call the scheduling algorithm to schedule the flows
    scheduleFlows(flows_to_schedule, flow_arrivals, channels, per_pkt_lat);

    return 0;
}
