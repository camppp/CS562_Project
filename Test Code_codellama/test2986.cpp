class UI_Radio {
public:
    // Constructor
    UI_Radio(const std::string& name, const std::string& group) :
        name_(name), group_(group), selected_(false) {}

    // Destructor
    ~UI_Radio() {}

    // Method to set the state of the radio button
    void select() {
        selected_ = true;
    }

    void deselect() {
        selected_ = false;
    }

    // Method to check if the radio button is selected
    bool is_selected() const {
        return selected_;
    }

    // Method to handle the click event
    void OnClickBegin(const std::string& position, const std::string& screen_position, const std::string& button_info, const std::string& qualifiers, const std::string& cursor) {
        if (selected_) {
            deselect();
        } else {
            select();
        }
    }

private:
    // Member variables to store the state of the radio button
    std::string name_;
    std::string group_;
    bool selected_;
};
