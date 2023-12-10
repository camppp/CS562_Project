bool isValidVariableName(const string& name) {
    // Check if the name starts with a letter or an underscore
    if (!(name[0] >= 'a' && name[0] <= 'z' || name[0] >= 'A' && name[0] <= 'Z' || name[0] == '_')) {
        return false;
    }

    // Check if the name contains only letters, digits, or underscores
    for (int i = 1; i < name.length(); i++) {
        if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] >= '0' && name[i] <= '9' || name[i] == '_')) {
            return false;
        }
    }

    // Check if the name is at least one character long
    if (name.length() < 1) {
        return false;
    }

    return true;
}
