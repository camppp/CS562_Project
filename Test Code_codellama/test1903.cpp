c
bool isExpired(const char* expirationDate) {
    // Get the current date
    time_t now = time(NULL);
    struct tm* now_tm = localtime(&now);

    // Convert the expiration date to a time_t value
    struct tm expiration_tm;
    strptime(expirationDate, "%Y-%m-%d", &expiration_tm);
    time_t expiration = mktime(&expiration_tm);

    // Check if the expiration date has passed
    return now > expiration;
}
