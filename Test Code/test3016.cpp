#include <vector>
#include <click/flow/flow.hh>
#include <click/flow/flowelement.hh>

CLICK_DECLS

enum TcpStatus {TCP_FIRSTSEEN = 0, TCP_DROP};

class TCPStatusFlowData {
public:
    enum TcpStatus status;

    TCPStatusFlowData() : status(TCP_FIRSTSEEN) {} // Initialize status to TCP_FIRSTSEEN
};

class TCPStatus : public FlowSpaceElement<TCPStatusFlowData> {
public:
    void initializeStatus(Flow *flow) {
        TCPStatusFlowData *data = this->getMutableData(flow);
        data->status = TCP_FIRSTSEEN;
    }

    void updateStatus(Flow *flow) {
        TCPStatusFlowData *data = this->getMutableData(flow);
        data->status = TCP_DROP;
    }

    enum TcpStatus getStatus(Flow *flow) {
        TCPStatusFlowData *data = this->getData(flow);
        return data->status;
    }
};
