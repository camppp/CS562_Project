#include <map>
#include <string>

class CaptivePortal {
private:
    WebServer _httpServer;
    IPAddress _apIP;
    bool _isStopped;
    std::map<int, std::string> _registeredUsers; // Map to store registered users with their registration IDs

public:
    CaptivePortal(const char* ip)
        : _httpServer(80),
          _isStopped(true)
    {
        _apIP.fromString(ip);
        _callbacks["/"] = [](WebServer& sv)
        {
            sv.setContentLength(CONTENT_LENGTH_UNKNOWN);
            // More code for handling HTTP requests
        };
        // Additional initialization and configuration
    }

    int registerUser(const std::string& userInfo) {
        static int nextID = 1; // Static variable to generate unique registration IDs
        _registeredUsers[nextID] = userInfo;
        return nextID++; // Return the current ID and then increment for the next user
    }

    bool authenticateUser(int registrationID) {
        return _registeredUsers.find(registrationID) != _registeredUsers.end();
    }

    void start() {
        _httpServer.begin();
        _isStopped = false;
    }
};
