char* intToString(int num) {
    char* str = new char[10];
    sprintf(str, "%d", num);
    return str;
}
