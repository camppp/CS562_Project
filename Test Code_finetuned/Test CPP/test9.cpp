#include <iostream>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    std::string data((const char*) ptr, (size_t) size * nmemb);
    *((std::stringstream*) stream) << data << std::endl;
    return size * nmemb;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        std::cout << "Usage: `echo_client test_url`" << std::endl;
        return 1;
    }

    std::string uri = argv[1];

    CURL *curl;
    CURLcode res;
    std::stringstream out;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    std::cout << out.str();

    return 0;
}