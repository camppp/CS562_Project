bool auth(const std::string& username, const std::string& password, const std::string& database, std::string& errmsg) {
    if (username == "test" && password == "eliot" && database == "bar") {
        return true;  // Authentication successful
    } else {
        errmsg = "Authentication failed: Invalid username, password, or database";
        return false;  // Authentication failed
    }
}
