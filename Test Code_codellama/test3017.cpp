c
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
        } else {
            *body = chunk.data;
            *size = chunk.size;
        }

        curl_easy_cleanup(ctx);
    }
}
