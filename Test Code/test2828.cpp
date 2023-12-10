#include <iostream>
#include <string>

class Server {
public:
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

    void handleRequest(const std::string& request) {
        // Extract the path from the request
        size_t start = request.find(' ');
        size_t end = request.find(' ', start + 1);
        std::string path = request.substr(start + 1, end - start - 1);

        // Process the path (for demonstration purposes, simply print it)
        std::cout << "Processing request for path: " << path << std::endl;
    }

    std::string generateResponse(int statusCode) {
        switch (statusCode) {
            case 200:
                return "200 OK";
            case 404:
                return "404 Not Found";
            case 500:
                return "500 Internal Server Error";
            default:
                return "Invalid status code";
        }
    }
};

int main() {
    Server server;

    // Example usage
    server.handleRequest("GET /index.html HTTP/1.1");
    std::string response = server.generateResponse(200);
    std::cout << "Generated response: " << response << std::endl;

    return 0;
}
