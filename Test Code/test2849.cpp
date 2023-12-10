#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Flow class
class Flow {
public:
    Flow(int src, int dst, int qos, int size) : src(src), dst(dst), qos(qos), size(size) {}
    int src;
    int dst;
    int qos;
    int size;
};

// Event class
class Event {
public:
    Event(int time, int flow) : time(time), flow(flow) {}
    int time;
    int flow;
};

// AggChannel class
class AggChannel {
public:
    AggChannel(int src, int dst, int qos, int size) : src(src), dst(dst), qos(qos), size(size) {}
    int src;
    int dst;
    int qos;
    int size;
};

// Scheduling algorithm
void scheduleFlows(deque<Flow*> flows_to_schedule, deque<Event*> flow_arrivals, vector<map<pair<int, int>, AggChannel*>> channels, vector<vector<int>> per_pkt_lat) {
    // Sort the flows by arrival time
    sort(flows_to_schedule.begin(), flows_to_schedule.end(), [](Flow* f1, Flow* f2) {
        return f1->time < f2->time;
    });

    // Sort the channels by QoS level
    for (int i = 0; i < channels.size(); i++) {
        sort(channels[i].begin(), channels[i].end(), [](pair<int, int> p1, pair<int, int> p2) {
            return p1.second < p2.second;
        });
    }

    // Schedule the flows
    for (int i = 0; i < flows_to_schedule.size(); i++) {
        Flow* flow = flows_to_schedule[i];
        int src = flow->src;
        int dst = flow->dst;
        int qos = flow->qos;
        int size = flow->size;

        // Find the available channel with the highest QoS level that satisfies the flow's requirements
        for (int j = 0; j < channels.size(); j++) {
            if (channels[j].find(make_pair(src, dst)) != channels[j].end() && channels[j][make_pair(src, dst)]->qos >= qos) {
                AggChannel* channel = channels[j][make_pair(src, dst)];
                int channel_size = channel->size;
                int channel_qos = channel->qos;

                // Check if the channel has enough capacity to accommodate the flow
                if (channel_size + size <= channel_qos) {
                    // Schedule the flow on the channel
                    channel->size += size;
                    per_pkt_lat[j].push_back(size);
                    break;
                }
            }
        }
    }
}

int main() {
    // Initialize the data structures
    deque<Flow*> flows_to_schedule;
    deque<Event*> flow_arrivals;
    vector<map<pair<int, int>, AggChannel*>> channels;
    vector<vector<int>> per_pkt_lat;

    // Add flows and arrival events to the data structures
    // ...

    // Schedule the flows
    scheduleFlows(flows_to_schedule, flow_arrivals, channels, per_pkt_lat);

    // Print the per-packet latency for each flow
    for (int i = 0; i < per_pkt_lat.size(); i++) {
        for (int j = 0; j < per_pkt_lat[i].size(); j++) {
            cout << per_pkt_lat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
