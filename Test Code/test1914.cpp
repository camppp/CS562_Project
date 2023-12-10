#include <iostream>
#include <iomanip>
#include <sstream>

class Bitcoin {
public:
    struct TxIn {
        uint32_t nSequence;
        // Other members not shown for brevity
    };

    friend std::ostream& operator<<(std::ostream& os, const TxIn& v) {
        os.write(reinterpret_cast<const char*>(&v.nSequence), sizeof(v.nSequence));
        return os;
    }

    friend std::istream& operator>>(std::istream& is, TxIn& v) {
        is.read(reinterpret_cast<char*>(&v.prevTxid), sizeof(v.prevTxid));
        is >> v.scriptSigLen;
        // Additional deserialization logic for other members if needed
        return is;
    }
};

int main() {
    Bitcoin::TxIn txIn;
    txIn.nSequence = 123456;  // Sample nSequence value

    // Serialization
    std::stringstream ss;
    ss << txIn;

    // Deserialization
    Bitcoin::TxIn deserializedTxIn;
    ss >> deserializedTxIn;
    
    // Verify deserialized values
    std::cout << "Deserialized nSequence: " << deserializedTxIn.nSequence << std::endl;

    return 0;
}
