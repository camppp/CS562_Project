void reverse_string(const char *str)
{
    char* reversed = new char[strlen(str) + 1];
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';
    // Your implementation here
    char* temp = new char[strlen(reversed) + 1];
    strncpy(temp, reversed, strlen(reversed) + 1);
    // temp now contains the reversed string
    delete[] temp;
    delete[] reversed;
}
