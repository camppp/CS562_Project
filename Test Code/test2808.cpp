#include <CoreInternalOutcome.h>
#include <Core/Error.h>

CoreInternalOutcome DeserializeWebSocket(const rapidjson::Value& jsonValue) {
    // Check if the JSON value is valid
    if (!jsonValue.IsObject()) {
        return CoreInternalOutcome(Core::Error("Invalid JSON value"));
    }

    // Get the request ID from the JSON value
    int requestId = jsonValue["requestId"].GetInt();

    // Deserialize the WebSocket object
    WebSocket webSocket;
    if (!webSocket.Deserialize(jsonValue)) {
        return CoreInternalOutcome(Core::Error("Failed to deserialize WebSocket object", requestId));
    }

    // Return success
    return CoreInternalOutcome(true);
}
