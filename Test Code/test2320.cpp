#include <iostream>
#include <cstring>

// Class to represent the address of the message recipient
class Address {
private:
    int recipientID;

public:
    void AddRecipient(int id) {
        recipientID = id;
    }

    int GetRecipientID() const {
        return recipientID;
    }
};

// Class to represent a tagged message
class TaggedMessage {
private:
    char* payload;
    size_t size;
    int tag;

public:
    TaggedMessage(const void* data, size_t dataSize, int messageTag) {
        payload = new char[dataSize];
        std::memcpy(payload, data, dataSize);
        size = dataSize;
        tag = messageTag;
    }

    ~TaggedMessage() {
        delete[] payload;
    }

    const char* GetPayload() const {
        return payload;
    }

    size_t GetSize() const {
        return size;
    }

    int GetTag() const {
        return tag;
    }
};

int main() {
    Address address;
    address.AddRecipient(123); // Adding recipient ID

    const char kPoisonMessage[] = "System shutdown";
    TaggedMessage message(kPoisonMessage, sizeof(kPoisonMessage), 1); // Creating a tagged message

    std::cout << "Recipient ID: " << address.GetRecipientID() << std::endl;
    std::cout << "Message Tag: " << message.GetTag() << std::endl;
    std::cout << "Message Payload: " << message.GetPayload() << std::endl;
    std::cout << "Message Size: " << message.GetSize() << std::endl;

    return 0;
}
