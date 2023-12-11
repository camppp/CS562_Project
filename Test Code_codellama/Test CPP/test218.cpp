#pragma once

#include <string>

enum class HttpMethod {
    GET,
    POST,
    PUT,
    DELETE
};

class HttpRequest {
private:
    HttpMethod method;
    std::string url;
    std::string body;

public:
    // Constructor to initialize the method and URL
    HttpRequest(HttpMethod method, const std::string& url) : method(method), url(url) {}

    // Method to set the request body
    void setBody(const std::string& body) {
        this->body = body;
    }

    // Getter for the HTTP method
    HttpMethod getMethod() const {
        return method;
    }

    // Getter for the URL
    const std::string& getUrl() const {
        return url;
    }

    // Getter for the request body
    const std::string& getBody() const {
        return body;
    }
};
