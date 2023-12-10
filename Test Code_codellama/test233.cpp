class RootScrollerManager {
public:
    RootScrollerManager(Frame* frame)
        : m_frame(frame)
    {
    }

    void updateRootScroller(Element* rootScroller)
    {
        if (m_rootScroller != rootScroller) {
            m_rootScroller = rootScroller;
            scheduleVisualUpdate();
        }
    }

    Element* getRootScroller() const
    {
        return m_rootScroller;
    }

private:
    Frame* m_frame;
    Element* m_rootScroller;

    void scheduleVisualUpdate()
    {
        if (!m_frame->isThrottled()) {
            m_frame->scheduleVisualUpdate();
        }
    }
};
