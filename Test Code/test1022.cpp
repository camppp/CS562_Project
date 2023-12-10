#include "../Container/Container.hpp"
#include "../Logging/Logger.hpp"
#include "./Handlers/HttpServerRequestHandlerBase.hpp"
#include "./HttpServerConfiguration.hpp"

class HttpServerRequestHandlerBase {
private:
    HttpServerConfiguration serverConfig;
    Container requestData;
    Logger logger;

public:
    HttpServerRequestHandlerBase(const HttpServerConfiguration& config)
        : serverConfig(config) {}

    void processRequest(const HttpRequest& request) {
        // Process the incoming HTTP request based on the server configuration
        // (implementation details depend on the specific requirements of the configuration)

        // Store request data using the Container class
        requestData.store(request);

        // Log the processing of the incoming request using the Logger class
        logger.log("Processing request: " + request.toString());
    }
};
