#include <iostream>
#include <string>
#include <stdexcept>

class EmailManager {
private:
    std::string mailServer;
    bool connected;

public:
    EmailManager(const std::string& mailServer) : mailServer(mailServer), connected(false) {
        // Initialize mail server connection here
        // Example: connectToMailServer(mailServer);
        connected = true;  // Assume successful connection
    }

    void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) {
        if (!connected) {
            throw std::runtime_error("User is not connected to the mail server");
        }
        // Send email using the connected mail server
        // Example: sendMail(recipient, subject, body);
        std::cout << "Email sent to " << recipient << " with subject: " << subject << std::endl;
    }
};

int main() {
    EmailManager emailManager("mail.example.com");
    emailManager.sendEmail("recipient@example.com", "Test Subject", "This is a test email body");
    return 0;
}
