#include <string>
#include <vector>
#include <memory>
#include <functional>

class url_pattern {
public:
    virtual bool match(const std::string& path) const = 0;
};

class exact_url_pattern : public url_pattern {
public:
    explicit exact_url_pattern(const std::string& url) : url_(url) {}

    bool match(const std::string& path) const override {
        return path == url_;
    }

private:
    std::string url_;
};

class wildcard_url_pattern : public url_pattern {
public:
    explicit wildcard_url_pattern(const std::string& url) : url_(url) {}

    bool match(const std::string& path) const override {
        return path.find(url_) != std::string::npos;
    }

private:
    std::string url_;
};

class parameterized_url_pattern : public url_pattern {
public:
    explicit parameterized_url_pattern(const std::string& url) : url_(url) {}

    bool match(const std::string& path) const override {
        return path.find(url_) != std::string::npos;
    }

private:
    std::string url_;
};

std::unique_ptr<http::IResponse> fn(http::IRequest* request, conf::Settings* settings) {
    // Handle the HTTP request
    // ...

    return std::make_unique<http::IResponse>(...);
}

int main() {
    // Create a vector of URL patterns
    std::vector<std::unique_ptr<url_pattern>> patterns;
    patterns.emplace_back(std::make_unique<exact_url_pattern>("https://example.com/path1"));
    patterns.emplace_back(std::make_unique<wildcard_url_pattern>("https://example.com/path2/*"));
    patterns.emplace_back(std::make_unique<parameterized_url_pattern>("https://example.com/path3/{param}"));

    // Iterate through the URL patterns and check if the current request path matches any of them
    for (const auto& pattern : patterns) {
        if (pattern->match(request->get_path())) {
            // If a match is found, assign the lambda function to handle the request
            request->set_handler(fn);
            break;
        }
    }

    // Handle the HTTP request
    request->handle();

    return 0;
}
