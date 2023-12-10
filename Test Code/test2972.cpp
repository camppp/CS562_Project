#include <array>
#include <string>
#include <json_lib>

enum req_type { NODES_POST, NODES_DELETE, NODES_GET, NODES_PUT_START, NODES_PUT_END, EDGES_POST, EDGES_DELETE, EDGES_GET, EDGES_PUT_START, EDGES_PUT_END };

req_type make_req_type(const json_object& obj) {
    if (obj.contains("action")) {
        std::string action = obj["action"].as_string();
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
        std::string method = obj["method"].as_string();
        if (method == "POST") {
            return EDGES_POST;
        } else if (method == "DELETE") {
            return EDGES_DELETE;
        } else if (method == "GET") {
            return EDGES_GET;
        } else if (method == "PUT_START") {
            return EDGES_PUT_START;
        } else if (method == "PUT_END") {
            return EDGES_PUT_END;
        }
    }
    // Default return value if no match is found
    return NODES_POST; // or any other appropriate default value
}
