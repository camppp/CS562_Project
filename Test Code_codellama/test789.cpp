void processRussianInput(const QString& inputKey)
{
    // Check if the input key corresponds to a Russian character
    if (inputKey.length() == 1 && inputKey.at(0).isLetter() &&
        (inputKey.at(0).toLatin1() >= 'А' && inputKey.at(0).toLatin1() <= 'Я' ||
         inputKey.at(0).toLatin1() == 'Ё'))
    {
        // Handle the selection and item details
        detailsCheckSelectionAndItem();

        // Apply character styling based on neighboring characters
        detailsSetCharStyleByNeighbours();

        // Update the charStyleVector_ with the character and its position
        charStyleVector_.push_back(QTextCharFormat(inputKey.at(0)));

        // Invoke the QTextEdit::keyPressEvent method to handle the key press event
        QTextEdit::keyPressEvent(inputKey.at(0));
    }
}
