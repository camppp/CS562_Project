#include <string>
#include <stdexcept>

class EmailManager {
public:
    EmailManager(const std::string& mailServer) {
        // Initialize the mail server connection
        // ...
    }

    void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) {
        // Check if the user is connected to the mail server
        if (!isConnected()) {
            throw std::runtime_error("User is not connected to the mail server");
        }

        // Send the email message using the connected mail server
        // ...
    }

private:
    bool isConnected() {
        // Check if the mail server connection is established
        // ...
    }
};
