#include <iostream>
#include <string>

// Enum for TCP status
enum TcpStatus {
    TCP_FIRSTSEEN,
    TCP_DROP,
    TCP_ESTABLISHED,
    TCP_CLOSED
};

// Class for TCP status flow data
class TCPStatusFlowData {
public:
    TcpStatus status;
    std::string connectionId;

    TCPStatusFlowData(TcpStatus status, std::string connectionId) {
        this->status = status;
        this->connectionId = connectionId;
    }
};

// Class for TCP status
class TCPStatus : public FlowSpaceElement<TCPStatusFlowData> {
public:
    // Method to initialize the TCP status of a connection to TCP_FIRSTSEEN
    void init(std::string connectionId) {
        TCPStatusFlowData data(TCP_FIRSTSEEN, connectionId);
        this->add(data);
    }

    // Method to update the TCP status of a connection to TCP_DROP
    void update(std::string connectionId) {
        TCPStatusFlowData data(TCP_DROP, connectionId);
        this->add(data);
    }

    // Method to retrieve the current TCP status of a connection
    TcpStatus getStatus(std::string connectionId) {
        TCPStatusFlowData data = this->get(connectionId);
        return data.status;
    }
};

int main() {
    // Initialize the TCP status of a connection to TCP_FIRSTSEEN
    TCPStatus tcpStatus;
    tcpStatus.init("12345");

    // Update the TCP status of a connection to TCP_DROP
    tcpStatus.update("12345");

    // Retrieve the current TCP status of a connection
    TcpStatus status = tcpStatus.getStatus("12345");
    std::cout << "TCP status: " << status << std::endl;

    return 0;
}
