#include <curl/curl.h>
#include <string>
#include <vector>
#include <stdexcept>

class CookieManager {
public:
    void addCookie(std::string_view kv) {
        overriddenCookies_.push_back(std::string(kv));
    }

    std::vector<std::string> getCookies() const {
        return overriddenCookies_;
    }

    void performRequest() const {
        CURLcode err = curl_easy_perform(curl_);
        if (err != CURLE_OK) {
            std::string error = curl_easy_strerror(err);
            throw std::runtime_error("Cannot perform curl request: " + error);
        }
    }

private:
    CURL* curl_;
    std::vector<std::string> overriddenCookies_;
};
