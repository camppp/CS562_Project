void ConnectionsHandler::handleGETRequest(Poco::Net::HTTPServerRequest &request,
                                          Poco::Net::HTTPServerResponse &response) {
    // Extract the request URI from the request object
    std::string uri = request.getURI();

    // Parse the request URI to extract the parameters
    Poco::URI requestURI(uri);
    Poco::URI::QueryParameters queryParams = requestURI.getQueryParameters();

    // Process the extracted parameters
    for (const auto &param : queryParams) {
        // Perform processing based on the parameter key-value pairs
        // Example: If the parameter is "id=123", process the ID value 123
        if (param.first == "id") {
            int id = std::stoi(param.second);
            // Perform processing based on the ID value
            // Example: Fetch data associated with the ID from a database
            // Process the data and prepare the response
            std::string responseData = "Data for ID " + std::to_string(id);
            // Set the response content type and body
            response.setContentType("text/plain");
            response.send() << responseData;
            return;
        }
    }

    // If no specific parameter processing is required, send a generic response
    response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
    response.setContentType("text/plain");
    response.send() << "Generic response for GET request";
}
