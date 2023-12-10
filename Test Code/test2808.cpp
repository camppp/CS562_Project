#include <iostream>
#include <string>
#include <json/json.h>

class CoreInternalOutcome {
public:
    CoreInternalOutcome() {}
    CoreInternalOutcome(const Core::Error& error) : m_error(error) {}

    bool IsSuccess() const {
        return !m_error.IsValid();
    }

    Core::Error GetError() const {
        return m_error;
    }

private:
    Core::Error m_error;
};

class Core::Error {
public:
    Error(const std::string& message) : m_message(message) {}

    void SetRequestId(const std::string& requestId) {
        m_requestId = requestId;
    }

    std::string GetMessage() const {
        return m_message;
    }

    std::string GetRequestId() const {
        return m_requestId;
    }

private:
    std::string m_message;
    std::string m_requestId;
};

class WebSocket {
    // Define the WebSocket class as per the system's requirements
};

CoreInternalOutcome DeserializeWebSocket(const Json::Value& value, const std::string& requestId) {
    if (!value.isObject()) {
        return CoreInternalOutcome(Core::Error("response `DomainDetailInfo.WebSocket` is not object type").SetRequestId(requestId));
    }

    WebSocket m_webSocket;
    CoreInternalOutcome outcome = m_webSocket.Deserialize(value["WebSocket"]);
    if (!outcome.IsSuccess()) {
        outcome.GetError().SetRequestId(requestId);
        return outcome;
    }

    // Additional processing if deserialization is successful

    return outcome;
}

int main() {
    // Example usage
    Json::Value jsonValue;  // Assume jsonValue is initialized with the WebSocket object JSON
    std::string requestId = "12345";  // Example request ID

    CoreInternalOutcome result = DeserializeWebSocket(jsonValue, requestId);
    if (result.IsSuccess()) {
        std::cout << "WebSocket deserialization successful" << std::endl;
    } else {
        Core::Error error = result.GetError();
        std::cout << "WebSocket deserialization failed with error: " << error.GetMessage() << " for request ID: " << error.GetRequestId() << std::endl;
    }

    return 0;
}
