class BasicModeRxEngine {
public:
    SDU processPdu(PDU pdu) {
        if (!pdu.is_valid()) {
            return SDU();
        }

        SDU sdu(pdu.length());
        pdu.Copy(sdu.get());
        return sdu;
    }
};
