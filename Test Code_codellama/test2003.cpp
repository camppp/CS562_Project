#include <iostream>
#include <string>

namespace HTTP::RespSource {

class Response {
protected:
    int responseCode;

public:
    Response(int responseCode) : responseCode(responseCode) {}

    virtual void sendResponse() {
        std::cout << "Response code: " << responseCode << std::endl;
    }

    virtual std::string getResponseType() = 0;
};

class ErrorRespSource : public Response {
private:
    std::string errorMessage;

public:
    ErrorRespSource(int responseCode, std::string errorMessage) : Response(responseCode), errorMessage(errorMessage) {}

    void sendResponse() {
        std::cout << "Response code: " << responseCode << std::endl;
        std::cout << "Error message: " << errorMessage << std::endl;
    }

    std::string getResponseType() {
        return "Error";
    }
};

} // namespace HTTP::RespSource
