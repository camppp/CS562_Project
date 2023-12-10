#include "PlayerDataType.hh"
#include <vector>

class PlaylistManager {
public:
    void addSong(const Song& song) {
        songs.push_back(song);
    }

    void removeSong(const std::string& title) {
        for (auto it = songs.begin(); it != songs.end(); ++it) {
            if (it->title == title) {
                songs.erase(it);
                break;
            }
        }
    }

    int getTotalDuration() const {
        int totalDuration = 0;
        for (const auto& song : songs) {
            totalDuration += song.duration;
        }
        return totalDuration;
    }

    int getNumberOfSongs() const {
        return songs.size();
    }

private:
    std::vector<Song> songs;
};
