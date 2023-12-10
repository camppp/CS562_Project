#include <string>
#include <unordered_map>

using FileType = std::string;
using FileExtension = std::string;

std::unordered_map<FileExtension, FileType> fileTypes = {
    {"txt", "text"},
    {"doc", "text"},
    {"docx", "text"},
    {"pdf", "text"},
    {"jpg", "image"},
    {"jpeg", "image"},
    {"png", "image"},
    {"gif", "image"},
    {"mp4", "video"},
    {"avi", "video"},
    {"mov", "video"},
    {"mkv", "video"},
    {"mp3", "audio"},
    {"wav", "audio"},
    {"flac", "audio"},
    {"aac", "audio"}
};

FileType fileTypeByExtension(const FileExtension& extension) {
    auto it = fileTypes.find(extension);
    if (it != fileTypes.end()) {
        return it->second;
    } else {
        return "unknown";
    }
}
