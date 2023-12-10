// Sample usage of the HttpRequest class
int main() {
    // Create an HTTP request object
    HttpRequest request(HttpMethod::POST, "https://api.example.com/data");

    // Set the request body
    request.setBody("{"data": "example"}");

    // Retrieve and print the HTTP method, URL, and body
    std::cout << "Method: " << static_cast<int>(request.getMethod()) << std::endl;
    std::cout << "URL: " << request.getUrl() << std::endl;
    std::cout << "Body: " << request.getBody() << std::endl;

    return 0;
}
