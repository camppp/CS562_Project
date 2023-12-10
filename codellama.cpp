#include <string>

string rotateString(string s, int n) {
    // Rotate the string to the right by n positions
    return s.substr(n) + s.substr(0, n);
}