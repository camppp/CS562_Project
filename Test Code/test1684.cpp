int StringCompareIgnoreCase(const char* str1, const char* str2)
{
    while (*str1 && *str2)
    {
        if (tolower(*str1) != tolower(*str2))
        {
            return tolower(*str1) - tolower(*str2);
        }
        str1++;
        str2++;
    }
    if (*str1 && !*str2)
    {
        return 1;
    }
    else if (!*str1 && *str2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
