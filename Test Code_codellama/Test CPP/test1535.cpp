#include <WebServer.h>
#include <WiFi.h>

class CaptivePortal {
public:
    CaptivePortal(const char* ip);
    ~CaptivePortal();

    void handleRegistration(const char* username, const char* password);
    bool authenticate(const char* username, const char* password);
    void start();

private:
    WebServer _httpServer;
    bool _isStopped;
    int _registerA;
    int _registerB;
    int _registerC;
    std::map<int, std::string> _registeredUsers;

    void handleRequest(WebServer& sv);
    void handleRegistrationRequest(WebServer& sv);
    void handleAuthenticationRequest(WebServer& sv);
};

CaptivePortal::CaptivePortal(const char* ip)
    : _httpServer(80),
      _isStopped(true),
      _registerA(0),
      _registerB(0),
      _registerC(0)
{
    _apIP.fromString(ip);
    _callbacks["/"] = [](WebServer& sv)
    {
        sv.setContentLength(CONTENT_LENGTH_UNKNOWN);
        handleRequest(sv);
    };
    _callbacks["/register"] = [](WebServer& sv)
    {
        sv.setContentLength(CONTENT_LENGTH_UNKNOWN);
        handleRegistrationRequest(sv);
    };
    _callbacks["/authenticate"] = [](WebServer& sv)
    {
        sv.setContentLength(CONTENT_LENGTH_UNKNOWN);
        handleAuthenticationRequest(sv);
    };
}

CaptivePortal::~CaptivePortal()
{
    _httpServer.stop();
}

void CaptivePortal::handleRegistration(const char* username, const char* password)
{
    int registrationID = _registerA++;
    if (registrationID == 0) {
        registrationID = _registerB++;
    }
    if (registrationID == 0) {
        registrationID = _registerC++;
    }
    _registeredUsers[registrationID] = username;
    sv.send(200, "OK", "Registration successful");
}

bool CaptivePortal::authenticate(const char* username, const char* password)
{
    int registrationID = _registeredUsers[username];
    if (registrationID == 0) {
        return false;
    }
    if (strcmp(password, _registeredUsers[username]) == 0) {
        return true;
    }
    return false;
}

void CaptivePortal::start()
{
    _httpServer.start();
    _isStopped = false;
}

void CaptivePortal::handleRequest(WebServer& sv)
{
    if (_isStopped) {
        sv.send(404, "Not Found", "Captive Portal is not running");
        return;
    }
    sv.send(200, "OK", "Captive Portal is running");
}

void CaptivePortal::handleRegistrationRequest(WebServer& sv)
{
    if (_isStopped) {
        sv.send(404, "Not Found", "Captive Portal is not running");
        return;
    }
    if (sv.hasArg("username") && sv.hasArg("password")) {
        handleRegistration(sv.arg("username"), sv.arg("password"));
    } else {
        sv.send(400, "Bad Request", "Missing required arguments");
    }
}

void CaptivePortal::handleAuthenticationRequest(WebServer& sv)
{
    if (_isStopped) {
        sv.send(404, "Not Found", "Captive Portal is not running");
        return;
    }
    if (sv.hasArg("username") && sv.hasArg("password")) {
        if (authenticate(sv.arg("username"), sv.arg("password"))) {
            sv.send(200, "OK", "Authentication successful");
        } else {
            sv.send(401, "Unauthorized", "Invalid username or password");
        }
    } else {
        sv.send(400, "Bad Request", "Missing required arguments");
    }
}
