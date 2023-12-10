#include <iostream>
#include <future>
#include <json/json.h>
#include <cpprest/http_client.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

// Function to send HTTP GET request and return JSON response
Json::Value sendHttpRequest(const std::string& ip, int port, const std::string& endpoint) {
    http_client client("http://" + ip + ":" + std::to_string(port));
    uri_builder builder(endpoint);
    pplx::task<http_response> response = client.request(methods::GET, builder.to_string());
    http_response httpResponse = response.get();
    return httpResponse.extract_json().get();
}

int main() {
    std::string ip = "127.0.0.1";
    int port = 5000;
    std::vector<std::future<Json::Value>> results;

    // Asynchronously send HTTP requests to multiple endpoints
    results.push_back(std::async(std::launch::async, sendHttpRequest, ip, port, "/endpoint1"));
    results.push_back(std::async(std::launch::async, sendHttpRequest, ip, port, "/endpoint2"));
    results.push_back(std::async(std::launch::async, sendHttpRequest, ip, port, "/endpoint3"));

    // Retrieve and process the JSON responses
    for (auto& result : results) {
        Json::Value jsonResponse = result.get();
        std::cout << jsonResponse << std::endl;  // Print JSON response to console
    }

    return 0;
}
