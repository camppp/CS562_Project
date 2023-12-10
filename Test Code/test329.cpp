bool compareConvertedString(QString input) {
    QString convertedString = toch(input); // Convert the input string using the toch function
    char stop_str[100] = "exmpl"; // Predefined string stored in a character array

    // Compare the converted string with the predefined string
    if (convertedString.toStdString() == stop_str) {
        return true; // Return true if the converted string matches stop_str
    } else {
        return false; // Return false if the converted string does not match stop_str
    }
}
