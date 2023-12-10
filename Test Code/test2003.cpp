#include <iostream>
#include <string>

namespace HTTP
{
    class Response
    {
    protected:
        int responseCode;

    public:
        Response(int code) : responseCode(code) {}

        void sendResponse()
        {
            std::cout << "Response Code: " << responseCode << std::endl;
        }

        virtual std::string getResponseType() = 0;
    };

    namespace RespSource
    {
        class ErrorRespSource : public Response
        {
    private:
        std::string errorMessage;

    public:
        ErrorRespSource(int code, const std::string &message) : Response(code), errorMessage(message) {}

        void sendResponse()
        {
            std::cout << "Response Code: " << responseCode << ", Error Message: " << errorMessage << std::endl;
        }

        std::string getResponseType() override
        {
            return "Error";
        }
    };

    class RedirectResponse : public Response
    {
    private:
        std::string targetLocation;

    public:
        RedirectResponse(const std::string &target, bool isPermanent) : Response(isPermanent ? 301 : 302), targetLocation(target) {}
    };
    }
}
