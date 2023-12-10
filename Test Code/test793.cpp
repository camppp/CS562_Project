#include <unordered_map>
#include <chrono>
#include <mutex>

// Define a data structure to store request counts per client IP address
std::unordered_map<std::string, std::pair<int, std::chrono::time_point<std::chrono::steady_clock>>> requestCounts;
std::mutex requestCountsMutex;

// Function to handle the _v1_all endpoint requests with rate limiting
void _v1_all(const Rest::Request& request, Http::ResponseWriter response) {
    std::string clientIP = request.address().host();
    std::lock_guard<std::mutex> lock(requestCountsMutex);

    auto currentTime = std::chrono::steady_clock::now();
    if (requestCounts.find(clientIP) == requestCounts.end() || 
        currentTime - requestCounts[clientIP].second >= std::chrono::seconds(T)) {
        // Reset request count if the time window has elapsed
        requestCounts[clientIP] = {1, currentTime};
    } else {
        // Increment request count if within the time window
        requestCounts[clientIP].first++;
    }

    if (requestCounts[clientIP].first > N) {
        // Respond with 429 status code if request limit exceeded
        response.headers().add<Http::Header::AccessControlAllowOrigin>("*");
        response.send(Pistache::Http::Code::Too_Many_Requests, "Rate limit exceeded");
    } else {
        // Process the request
        // ...
    }
}
