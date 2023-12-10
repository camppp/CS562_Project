#include <string>
#include <vector>

using namespace std;

enum RequestType {
    NODES_POST,
    NODES_DELETE,
    NODES_GET,
    NODES_PUT_START,
    NODES_PUT_END
};

RequestType make_req_type(const json& obj) {
    if (obj.contains("action")) {
        string action = obj["action"];
        if (action == "POST") {
            return NODES_POST;
        } else if (action == "DELETE") {
            return NODES_DELETE;
        } else if (action == "GET") {
            return NODES_GET;
        } else if (action == "PUT_START") {
            return NODES_PUT_START;
        } else if (action == "PUT_END") {
            return NODES_PUT_END;
        }
    } else if (obj.contains("method")) {
        string method = obj["method"];
        if (method == "POST") {
            return NODES_POST;
        } else if (method == "DELETE") {
            return NODES_DELETE;
        } else if (method == "GET") {
            return NODES_GET;
        } else if (method == "PUT_START") {
            return NODES_PUT_START;
        } else if (method == "PUT_END") {
            return NODES_PUT_END;
        }
    }
    return NODES_GET;
}
