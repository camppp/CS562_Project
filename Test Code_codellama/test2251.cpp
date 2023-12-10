#include <QDebug>
#include <QPointer>
#include <QThread>
#include <unordered_map>

class VideoRequestor {
public:
    VideoRequestor() {}

    void addVideoRequest(const VideoRequest& request) {
        // Add the request to the pending requests map
        pendingRequests[request.getRequestId()] = request;

        // Start the processing thread if it is not already running
        if (!processingThread.isRunning()) {
            processingThread.start();
        }
    }

    void processVideoRequests() {
        // Process all pending requests in a separate thread
        QThread* thread = new QThread();
        thread->start();

        // Process each request in the pending requests map
        for (auto& request : pendingRequests) {
            VideoRequest* requestPtr = request.second;
            QPointer<VideoRequest> requestPtrPtr = requestPtr;

            // Process the request in a separate thread
            QObject::connect(thread, &QThread::finished, requestPtrPtr, &VideoRequest::process);
            QObject::connect(requestPtrPtr, &VideoRequest::statusChanged, this, &VideoRequestor::updateStatus);
            requestPtrPtr->process();
        }

        // Wait for the processing thread to finish
        thread->wait();

        // Update the status of each request
        for (auto& request : pendingRequests) {
            VideoRequest* requestPtr = request.second;
            QPointer<VideoRequest> requestPtrPtr = requestPtr;

            // Update the status of the request
            QObject::connect(requestPtrPtr, &VideoRequest::statusChanged, this, &VideoRequestor::updateStatus);
            requestPtrPtr->updateStatus();
        }
    }

    void updateStatus(const VideoRequest& request) {
        // Update the status of the request in the pending requests map
        pendingRequests[request.getRequestId()] = request;
    }

private:
    std::unordered_map<int, VideoRequest*> pendingRequests;
    QThread processingThread;
};
