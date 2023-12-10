#include <algorithm> // for std::max

class FileWatcher {
    // Assume the implementation of the FileWatcher class
};

class FileChangeNotifier {
private:
    bool m_bActive;
    FileWatcher* m_pFileWatcher;
    float m_fTimeUntilNextAllowedRecompile;
    float m_fFileChangeSpamTimeRemaining;

public:
    FileChangeNotifier(bool active, FileWatcher* fileWatcher, float timeUntilNextAllowedRecompile, float fileChangeSpamTimeRemaining)
        : m_bActive(active), m_pFileWatcher(fileWatcher), m_fTimeUntilNextAllowedRecompile(timeUntilNextAllowedRecompile), m_fFileChangeSpamTimeRemaining(fileChangeSpamTimeRemaining) {}

    void Update(float fDeltaTime) {
        if (m_bActive) {
            m_pFileWatcher->update();
            m_fTimeUntilNextAllowedRecompile = std::max(0.0f, m_fTimeUntilNextAllowedRecompile - fDeltaTime);
            m_fFileChangeSpamTimeRemaining = std::max(0.0f, m_fFileChangeSpamTimeRemaining - fDeltaTime);
        }
    }
};
