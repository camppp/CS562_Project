#include <iostream>
#include <string>

class Connection {
public:
    bool auth(const std::string& username, const std::string& password, const std::string& database, std::string& errmsg) {
        if (username == "test" && password == "eliot" && database == "bar") {
            return true;  // Authentication successful
        } else {
            errmsg = "Authentication failed: Invalid username, password, or database";
            return false;  // Authentication failed
        }
    }
};

int main() {
    Connection conn;
    std::string errmsg;

    bool ok = conn.auth("test", "eliot", "bar", errmsg);
    if (!ok) {
        std::cout << errmsg << std::endl;  // Output the error message
    }

    return 0;
}
