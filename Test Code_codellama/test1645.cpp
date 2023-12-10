void ConnectionsHandler::handleGETRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    // Extract the parameters from the request URL
    std::string url = request.getURI();
    std::string::size_type pos = url.find('?');
    if (pos != std::string::npos)
    {
        std::string params = url.substr(pos + 1);
        std::vector<std::string> paramPairs;
        Poco::StringTokenizer::split(params, '&', paramPairs);
        for (const auto &paramPair : paramPairs)
        {
            std::string::size_type eqPos = paramPair.find('=');
            if (eqPos != std::string::npos)
            {
                std::string paramName = paramPair.substr(0, eqPos);
                std::string paramValue = paramPair.substr(eqPos + 1);
                // Process the parameter according to the requirements of the application
                // ...
            }
        }
    }

    // Provide a response based on the processed parameters
    response.setContentType("text/plain");
    response.sendBuffer("Hello, World!");
}
