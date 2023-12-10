#include <curl/curl.h>
#include <string>
#include <vector>

class CookieManager {
 public:
  // Constructor
  CookieManager() : curl_(nullptr) {}

  // Add a cookie to the list of overridden cookies
  void addCookie(const std::string& key, const std::string& value) {
    cookies_.push_back(key + "=" + value);
  }

  // Get all the overridden cookies
  std::vector<std::string> getCookies() {
    return cookies_;
  }

  // Perform an HTTP request using libcurl
  void performRequest(const std::string& url) {
    CURL* curl = curl_easy_init();
    if (!curl) {
      throw std::runtime_error("Failed to initialize libcurl");
    }

    // Set the URL and the list of overridden cookies
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_COOKIE, cookies_.c_str());

    // Perform the request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      throw std::runtime_error("Failed to perform HTTP request: " +
                               std::string(curl_easy_strerror(res)));
    }

    // Clean up
    curl_easy_cleanup(curl);
  }

 private:
  // The list of overridden cookies
  std::vector<std::string> cookies_;

  // The libcurl handle
  CURL* curl_;
};
