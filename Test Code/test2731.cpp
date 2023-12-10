#include <vector>
#include <string>
#include "PlayerDataType.hh" // Include the header file containing the Song data type

class PlaylistManager {
private:
    std::vector<Song> playlist;

public:
    void addSong(const Song& song) {
        playlist.push_back(song);
    }

    void removeSong(const std::string& title) {
        for (auto it = playlist.begin(); it != playlist.end(); ++it) {
            if (it->title == title) {
                playlist.erase(it);
                break;
            }
        }
    }

    int getTotalDuration() const {
        int totalDuration = 0;
        for (const auto& song : playlist) {
            totalDuration += song.duration;
        }
        return totalDuration;
    }

    int getNumberOfSongs() const {
        return playlist.size();
    }
};
