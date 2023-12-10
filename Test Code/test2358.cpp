void HandleErrorResponse(const http_response& response) {
    if (response.status_code() == status_codes::InternalError) {
        std::unique_ptr<ErrorMessage> em = ErrorMessageFromJSON(response.extract_json().get());
        std::string errorMsg = wstring2string(em->msg);
        throw std::exception(errorMsg.c_str());
    }
}
