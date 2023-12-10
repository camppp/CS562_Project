class MessageQueue {
private:
    // Member variables
    bool m_bPauseOutput;
    bool m_bWaitPong;
    uint32_t m_c4PingVal;

    // Methods
    void pauseOutput() {
        m_bPauseOutput = true;
    }

    void resumeOutput() {
        m_bPauseOutput = false;
    }

    void sendPing(uint32_t c4PingVal) {
        // Send a ping message to the client, including the specified 32-bit value
        // ...
    }

    void handlePong(uint32_t c4ReceivedVal) {
        // Verify the received 32-bit value
        if (c4ReceivedVal == m_c4PingVal) {
            // Pong received successfully
            m_bWaitPong = false;
        } else {
            // Pong received with an error
            // ...
        }
    }
};
