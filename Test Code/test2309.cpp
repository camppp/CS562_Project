#include <iostream>
#include <string>
#include <curl/curl.h>

class Curl {
private:
    CURL* curlHandle;

public:
    Curl() {
        curl_global_init(CURL_GLOBAL_ALL);
        curlHandle = curl_easy_init();
    }

    ~Curl() {
        curl_easy_cleanup(curlHandle);
        curl_global_cleanup();
    }

    static bool perform() {
        // Perform HTTP request using curlHandle
        CURLcode res = curl_easy_perform(curlHandle);
        return (res == CURLE_OK);
    }

    static void print() {
        // Print HTTP response to console
        // Assume response is stored in a variable named httpResponse
        std::cout << httpResponse << std::endl;
    }

    static void getString(std::string& str) {
        // Store HTTP response in the provided string reference
        // Assume response is stored in a variable named httpResponse
        str = httpResponse;
    }
};
