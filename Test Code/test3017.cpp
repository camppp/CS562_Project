#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct WriteBuffer {
    char *data;
    size_t size;
};

size_t writeCallback(void *ptr, size_t size, size_t nmemb, void *data) {
    size_t realsize = size * nmemb;
    struct WriteBuffer *mem = (struct WriteBuffer *)data;

    mem->data = realloc(mem->data, mem->size + realsize + 1);
    if (mem->data == NULL) {
        // Handle memory allocation failure
        return 0;
    }

    memcpy(&(mem->data[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->data[mem->size] = 0;

    return realsize;
}

void downloadFile(const char *downloadUrl, char **body, size_t *size) {
    CURL *ctx = curl_easy_init();
    if (ctx) {
        struct WriteBuffer chunk;
        chunk.data = (char *)malloc(1);
        chunk.size = 0;

        curl_easy_setopt(ctx, CURLOPT_VERBOSE, 1);
        curl_easy_setopt(ctx, CURLOPT_URL, downloadUrl);
        curl_easy_setopt(ctx, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(ctx, CURLOPT_WRITEDATA, (void *)&chunk);

        CURLcode res = curl_easy_perform(ctx);
        if (res != CURLE_OK) {
            // Handle download failure
            fprintf(stderr, "Download failed: %s\n", curl_easy_strerror(res));
        } else {
            *body = chunk.data;
            *size = chunk.size;
        }

        curl_easy_cleanup(ctx);
    }
}

int main() {
    char *downloadUrl = "https://example.com/file.txt";
    char *fileContent;
    size_t fileSize;

    downloadFile(downloadUrl, &fileContent, &fileSize);

    if (fileContent) {
        printf("Downloaded file content: %s\n", fileContent);
        printf("File size: %zu bytes\n", fileSize);
        free(fileContent);
    } else {
        printf("File download failed\n");
    }

    return 0;
}
