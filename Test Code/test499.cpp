c
void process_packet(set<int>& pending_acks, int pkt_channel) {
    // Insert the channel of the received packet into the pending_acks set
    pending_acks.insert(pkt_channel);

    // Print a debug message if the debug flag is enabled
    #ifdef DEBUG_LINK
        cout << "Received pkt on channel " << pkt_channel << endl;
    #endif
}
