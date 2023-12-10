#include <iostream>
#include <string>
#include <unordered_map>

class DownloadManager {
private:
    std::unordered_map<std::string, bool> downloadTasks; // Map to store download tasks and their status

public:
    void StartDownload(const std::string& url) {
        // Start a new download task for the given URL
        downloadTasks[url] = true; // Set the task status to active
        std::cout << "Started download for URL: " << url << std::endl;
    }

    void PauseDownload(const std::string& url) {
        // Pause the download task associated with the given URL
        if (downloadTasks.find(url) != downloadTasks.end()) {
            downloadTasks[url] = false; // Set the task status to paused
            std::cout << "Paused download for URL: " << url << std::endl;
        } else {
            std::cout << "Download task not found for URL: " << url << std::endl;
        }
    }

    void ShutDown() {
        // Shut down the download manager and release any allocated resources
        for (auto& task : downloadTasks) {
            if (task.second) {
                std::cout << "Shutting down active download for URL: " << task.first << std::endl;
            }
        }
        downloadTasks.clear(); // Clear the download tasks map
        std::cout << "Download manager shut down" << std::endl;
    }
};

int main() {
    DownloadManager manager;
    manager.StartDownload("http://example.com/file1");
    manager.StartDownload("http://example.com/file2");
    manager.PauseDownload("http://example.com/file1");
    manager.ShutDown();

    return 0;
}
