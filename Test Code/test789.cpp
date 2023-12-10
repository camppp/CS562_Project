void processRussianInput(const std::string& inputKey) {
    std::string russianCharacters = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    
    if (inputKey.size() == 1 && russianCharacters.find(inputKey) != std::string::npos) {
        // Input key corresponds to a Russian character
        detailsCheckSelectionAndItem(cursorPos);
        detailsSetCharStyleByNeighbours(inputKey, cursorPos);
        charStyleVector_.insert(cursorPos, 1, inputKey);
        // Assuming cursorPos is the position where the character is to be inserted
        // Call the base method to handle the key press event
        QTextEdit::keyPressEvent(event);
        detailsSetCharStyleByIndex(inputKey, cursorPos + 1);
    }
}
