void HandleErrorResponse(const http_response& response) {
    if (response.status_code() == 500) {
        // Extract error message from JSON response
        std::string error_message = ErrorMessageFromJSON(response.body());
        // Throw exception with error message
        throw std::runtime_error(error_message);
    }
}
