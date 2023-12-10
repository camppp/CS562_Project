#include <iostream>
#include <future>
#include <vector>
#include <json/json.h>

using namespace std;

// Function to send an HTTP GET request and return the JSON response
Json::Value sendRequest(const string& ip, const string& port, const string& endpoint) {
    // Initialize the HTTP request
    HttpRequest request(ip, port, endpoint);

    // Send the HTTP request and get the response
    HttpResponse response = request.send();

    // Parse the JSON response
    Json::Value jsonResponse;
    Json::Reader reader;
    reader.parse(response.getBody(), jsonResponse);

    return jsonResponse;
}

int main() {
    // Initialize the IP address and port
    string ip = "127.0.0.1";
    string port = "8080";

    // Initialize the vector to store the results
    vector<future<Json::Value>> results;

    // Asynchronously send HTTP requests to the endpoints
    results.push_back(async(launch::async, sendRequest, ip, port, "/endpoint1"));
    results.push_back(async(launch::async, sendRequest, ip, port, "/endpoint2"));
    results.push_back(async(launch::async, sendRequest, ip, port, "/endpoint3"));

    // Wait for all requests to complete
    for (auto& result : results) {
        result.wait();
    }

    // Retrieve the JSON responses
    for (auto& result : results) {
        Json::Value jsonResponse = result.get();
        cout << jsonResponse << endl;
    }

    return 0;
}
