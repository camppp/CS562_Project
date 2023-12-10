#include <iostream>
#include <set>

void process_packet(std::set<int>& pending_acks, int pkt_channel) {
    pending_acks.insert(pkt_channel);
#if DEBUG_LINK
    std::cout << "Received pkt on channel " << pkt_channel << std::endl;
#endif
}
