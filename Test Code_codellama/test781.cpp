class LoginTooltipView : public LoginBaseBubbleView {
public:
    LoginTooltipView(const std::string& message, const Size& iconSize) : LoginBaseBubbleView(message, iconSize) {
        // Initialize member variables
        this->message = message;
        this->iconSize = iconSize;
    }

    // Set the message to be displayed in the tooltip view
    void setMessage(const std::string& message) {
        this->message = message;
    }

    // Set the size of the info icon in the tooltip view
    void setIconSize(const Size& iconSize) {
        this->iconSize = iconSize;
    }

    // Display the tooltip view next to the anchor view, showing the message and the info icon
    void display() {
        // Calculate the position of the tooltip view next to the anchor view
        Point position = calculatePosition();

        // Display the tooltip view at the calculated position
        displayAt(position);
    }

private:
    // The message to be displayed in the tooltip view
    std::string message;

    // The size of the info icon in the tooltip view
    Size iconSize;

    // Calculate the position of the tooltip view next to the anchor view
    Point calculatePosition() {
        // Calculate the position of the anchor view
        Point anchorPosition = getAnchorView().getPosition();

        // Calculate the position of the tooltip view next to the anchor view
        Point position = anchorPosition + Size(iconSize.width + 10, 0);

        return position;
    }
};
