#include <iostream>
#include <vector>

class UI_Radio {
private:
    bool selected_;
    static std::vector<UI_Radio*> radioGroup_;

public:
    UI_Radio() : selected_(false) {
        radioGroup_.push_back(this);
    }

    ~UI_Radio() = default;

    void OnClickBegin(const IntVector2& position, const IntVector2& screenPosition, int button, int buttons, int qualifiers, Cursor* cursor) {
        if (!selected_) {
            for (UI_Radio* radio : radioGroup_) {
                if (radio != this) {
                    radio->Deselect();
                }
            }
            Select();
        }
    }

    void Select() {
        selected_ = true;
        // Add visual feedback for selection
    }

    void Deselect() {
        selected_ = false;
        // Remove visual feedback for deselection
    }
};

std::vector<UI_Radio*> UI_Radio::radioGroup_;
