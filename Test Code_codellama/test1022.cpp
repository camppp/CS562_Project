#include "../Container/Container.hpp"
#include "../Logging/Logger.hpp"
#include "./Handlers/HttpServerRequestHandlerBase.hpp"
#include "./HttpServerConfiguration.hpp"

class HttpServerRequestHandlerBase {
public:
    HttpServerRequestHandlerBase(const HttpServerConfiguration& config)
        : config_(config) {}

    void processRequest(const HttpRequest& request) {
        // Use the Container class to store data related to the request
        Container container;

        // Use the Logger class to log the processing of the request
        Logger logger;

        // Process the request based on the server configuration
        if (config_.getRequestHandler() == RequestHandler::kDefault) {
            // Handle the request using the default handler
            handleDefaultRequest(request, container, logger);
        } else if (config_.getRequestHandler() == RequestHandler::kCustom) {
            // Handle the request using a custom handler
            handleCustomRequest(request, container, logger);
        }
    }

private:
    void handleDefaultRequest(const HttpRequest& request, Container& container, Logger& logger) {
        // Handle the request using the default handler
        // ...
    }

    void handleCustomRequest(const HttpRequest& request, Container& container, Logger& logger) {
        // Handle the request using a custom handler
        // ...
    }

    const HttpServerConfiguration& config_;
};
