#include <iostream>
#include <string>
#include <curl/curl.h>

class Curl {
public:
    Curl();
    ~Curl();

    static bool perform(std::string url);
    static void print(std::string url);
    static void getString(std::string& str);

private:
    CURL* curl;
    CURLcode res;
    std::string response;
};

Curl::Curl() {
    curl = curl_easy_init();
}

Curl::~Curl() {
    curl_easy_cleanup(curl);
}

bool Curl::perform(std::string url) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Curl error: " << curl_easy_strerror(res) << std::endl;
        return false;
    }
    return true;
}

void Curl::print(std::string url) {
    perform(url);
    std::cout << response << std::endl;
}

void Curl::getString(std::string& str) {
    perform(str);
    str = response;
}
