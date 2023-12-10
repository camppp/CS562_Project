class StringBuilder 
{
public:
    StringBuilder(const char* s) 
    {
        // Allocate memory for the string
        m_str = new char[strlen(s) + 1];
        strcpy(m_str, s);
    }

    ~StringBuilder() 
    {
        // Free the memory allocated for the string
        delete[] m_str;
    }

    void append(const char* s) 
    {
        // Allocate memory for the new string
        char* new_str = new char[strlen(m_str) + strlen(s) + 1];

        // Copy the current string to the new string
        strcpy(new_str, m_str);

        // Append the new string to the current string
        strcat(new_str, s);

        // Free the memory allocated for the current string
        delete[] m_str;

        // Update the current string to the new string
        m_str = new_str;
    }

    void append(char ch) 
    {
        // Allocate memory for the new string
        char* new_str = new char[strlen(m_str) + 2];

        // Copy the current string to the new string
        strcpy(new_str, m_str);

        // Append the new character to the current string
        new_str[strlen(m_str)] = ch;
        new_str[strlen(m_str) + 1] = '\0';

        // Free the memory allocated for the current string
        delete[] m_str;

        // Update the current string to the new string
        m_str = new_str;
    }

    std::string toString() 
    {
        return std::string(m_str);
    }

private:
    char* m_str;
};
