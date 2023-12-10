#include <krest/core/VideoRequest.hpp>
#include <QDebug>
#include <QPointer>
#include <QThread>
#include <unordered_map>
#include <mutex>
#include <thread>
#include <vector>

class VideoRequestor {
public:
    void addVideoRequest(const VideoRequest& request) {
        std::lock_guard<std::mutex> lock(requestsMutex);
        videoRequests[request.getRequestID()] = request;
    }

    void processVideoRequests() {
        std::vector<std::thread> threads;
        for (auto& entry : videoRequests) {
            threads.emplace_back(&VideoRequestor::processRequest, this, entry.first);
        }
        for (auto& t : threads) {
            t.join();
        }
    }

    void updateRequestStatus(int requestID, const QString& status) {
        std::lock_guard<std::mutex> lock(requestsMutex);
        if (videoRequests.find(requestID) != videoRequests.end()) {
            videoRequests[requestID].setStatus(status);
        }
    }

private:
    std::unordered_map<int, VideoRequest> videoRequests;
    std::mutex requestsMutex;

    void processRequest(int requestID) {
        // Simulate processing time
        std::this_thread::sleep_for(std::chrono::seconds(2));
        updateRequestStatus(requestID, "Processed");
        qDebug() << "Request ID" << requestID << "processed";
    }
};
