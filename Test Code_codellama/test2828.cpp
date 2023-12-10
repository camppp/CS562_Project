#include <string>
#include <unordered_map>

class Server {
public:
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

    void handleRequest(const std::string& request) {
        // Extract the path from the request
        size_t path_start = request.find('/');
        size_t path_end = request.find(' ', path_start);
        std::string path = request.substr(path_start, path_end - path_start);

        // Handle the request based on the path
        if (path == "/index.html") {
            // Handle GET requests for index.html
            handleGetRequest(path);
        } else if (path == "/about.html") {
            // Handle GET requests for about.html
            handleGetRequest(path);
        } else {
            // Handle other requests
            handleOtherRequest(path);
        }
    }

    std::string generateResponse(int statusCode) {
        // Generate a response message based on the status code
        std::string response;
        switch (statusCode) {
            case 200:
                response = "200 OK";
                break;
            case 404:
                response = "404 Not Found";
                break;
            case 500:
                response = "500 Internal Server Error";
                break;
            default:
                response = "Unknown Status Code";
                break;
        }
        return response;
    }

private:
    void handleGetRequest(const std::string& path) {
        // Handle GET requests for index.html and about.html
        std::string response = generateResponse(200);
        response += "\r\n";
        response += "Content-Type: text/html\r\n";
        response += "\r\n";
        response += "<html><body>Hello, world!</body></html>";
        sendResponse(response);
    }

    void handleOtherRequest(const std::string& path) {
        // Handle other requests
        std::string response = generateResponse(404);
        response += "\r\n";
        response += "Content-Type: text/html\r\n";
        response += "\r\n";
        response += "<html><body>Not Found</body></html>";
        sendResponse(response);
    }

    void sendResponse(const std::string& response) {
        // Send the response to the client
        // ...
    }
};
