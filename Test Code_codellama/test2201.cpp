c
CHIP_ERROR ExtractAccountId(const char *buf, size_t bufLen, char delimiter, char *accountId, size_t &accountIdLen) {
    // Find the delimiter in the input buffer
    const char *delimiterPos = strchr(buf, delimiter);
    if (delimiterPos == NULL) {
        // Delimiter not found, return an error
        accountIdLen = 0;
        return CHIP_ERROR_INVALID_ARGUMENT;
    }

    // Extract the account ID from the input buffer
    size_t accountIdLen = delimiterPos - buf;
    memcpy(accountId, buf, accountIdLen);
    accountId[accountIdLen] = '\0';

    // Return success
    return CHIP_NO_ERROR;
}
