CHIP_ERROR ExtractAccountId(const char *buf, size_t bufLen, char delimiter, char *accountId, size_t &accountIdLen)
{
    size_t i;
    for (i = 0; i < bufLen; i++)
    {
        if (buf[i] == delimiter)
        {
            memcpy(accountId, buf, i);
            accountId[i] = '\0';
            accountIdLen = i;
            return CHIP_NO_ERROR;
        }
    }
    accountIdLen = 0;
    return CHIP_ERROR_INVALID_ARGUMENT;
}
