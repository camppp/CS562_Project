class FileChangeNotifier
{
public:
    FileChangeNotifier() : m_bActive(false), m_pFileWatcher(nullptr), m_fTimeUntilNextAllowedRecompile(0.0f), m_fFileChangeSpamTimeRemaining(0.0f) {}

    void Update(float fDeltaTime)
    {
        if (m_bActive)
        {
            m_pFileWatcher->update();
            m_fTimeUntilNextAllowedRecompile -= fDeltaTime;
            m_fFileChangeSpamTimeRemaining -= fDeltaTime;
            if (m_fTimeUntilNextAllowedRecompile < 0.0f)
            {
                m_fTimeUntilNextAllowedRecompile = 0.0f;
            }
            if (m_fFileChangeSpamTimeRemaining < 0.0f)
            {
                m_fFileChangeSpamTimeRemaining = 0.0f;
            }
        }
    }

private:
    bool m_bActive;
    FileWatcher* m_pFileWatcher;
    float m_fTimeUntilNextAllowedRecompile;
    float m_fFileChangeSpamTimeRemaining;
};
