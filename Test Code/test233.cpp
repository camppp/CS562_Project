#include <iostream>

class LocalFrame {
public:
    void ScheduleVisualUpdateUnlessThrottled() {
        if (!throttled_) {
            std::cout << "Visual update scheduled for frame" << std::endl;
        } else {
            std::cout << "Frame is throttled, visual update not scheduled" << std::endl;
        }
    }

    void SetThrottled(bool throttled) {
        throttled_ = throttled;
    }

private:
    bool throttled_ = false;
};

class Document {
public:
    LocalFrame* GetFrame() {
        return &frame_;
    }

private:
    LocalFrame frame_;
};

class RootScrollerManager {
public:
    void UpdateRootScroller(LocalFrame* newRootScroller) {
        if (rootScroller_ == newRootScroller)
            return;

        rootScroller_ = newRootScroller;

        if (document_->GetFrame())
            document_->GetFrame()->ScheduleVisualUpdateUnlessThrottled();
    }

    LocalFrame* GetCurrentRootScroller() {
        return rootScroller_;
    }

private:
    LocalFrame* rootScroller_ = nullptr;
    Document* document_;
};

int main() {
    Document document;
    RootScrollerManager manager;
    manager.UpdateRootScroller(document.GetFrame());
    manager.UpdateRootScroller(document.GetFrame());  // No visual update scheduled as root scroller is not changed
    document.GetFrame()->SetThrottled(true);
    manager.UpdateRootScroller(document.GetFrame());  // No visual update scheduled as frame is throttled
    return 0;
}
