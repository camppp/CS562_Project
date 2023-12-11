#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

class DownloadManager {
public:
    DownloadManager() {
        // Initialize the download manager
        shutdown_ = false;
        downloads_ = std::vector<std::thread>();
        mutex_ = std::mutex();
        condition_ = std::condition_variable();
    }

    ~DownloadManager() {
        // Shut down the download manager
        shutdown_ = true;
        condition_.notify_all();
        for (auto& thread : downloads_) {
            thread.join();
        }
    }

    void StartDownload(const std::string& url) {
        // Start a new download task
        std::lock_guard<std::mutex> lock(mutex_);
        downloads_.emplace_back(std::thread([this, url] {
            // Download the file
            std::cout << "Downloading " << url << std::endl;
            // Wait for the download to complete
            condition_.wait(lock, [this] { return shutdown_; });
            // Notify the download manager that the download has completed
            condition_.notify_all();
        }));
    }

    void PauseDownload(const std::string& url) {
        // Pause the download task associated with the given URL
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto it = downloads_.begin(); it != downloads_.end(); ++it) {
            if ((*it).get_id() == url) {
                (*it).pause();
                break;
            }
        }
    }

    void ShutDown() {
        // Shut down the download manager
        std::lock_guard<std::mutex> lock(mutex_);
        shutdown_ = true;
        condition_.notify_all();
        for (auto& thread : downloads_) {
            thread.join();
        }
    }

private:
    bool shutdown_;
    std::vector<std::thread> downloads_;
    std::mutex mutex_;
    std::condition_variable condition_;
};
