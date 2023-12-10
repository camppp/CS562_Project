#include <iostream>
#include <cstdint>

struct TxIn {
    uint32_t nSequence;
    std::string prevTxid;
    std::size_t scriptSigLen;
};

std::ostream& operator<<(std::ostream& os, const TxIn& txin) {
    os.write((char*)&txin.nSequence, sizeof(txin.nSequence));
    os.write(txin.prevTxid.c_str(), txin.prevTxid.size());
    os.write((char*)&txin.scriptSigLen, sizeof(txin.scriptSigLen));
    return os;
}

std::istream& operator>>(std::istream& is, TxIn& txin) {
    is.read((char*)&txin.nSequence, sizeof(txin.nSequence));
    txin.prevTxid.resize(txin.scriptSigLen);
    is.read(txin.prevTxid.data(), txin.prevTxid.size());
    is.read((char*)&txin.scriptSigLen, sizeof(txin.scriptSigLen));
    return is;
}
