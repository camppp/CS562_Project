int main() {
    // Example usage
    CustomString s1("Hello");
    CustomString s2("World");

    cout << "Length of s1: " << s1.length() << endl;
    cout << "Length of s2: " << s2.length() << endl;

    CustomString s3 = s1.concatenate(s2);
    cout << "Concatenated string: " << s3.charAt(0) << "..." << s3.charAt(s3.length() - 1) << endl;

    CustomString s4 = s3.substring(6, 5);
    cout << "Substring: " << s4.charAt(0) << "..." << s4.charAt(s4.length() - 1) << endl;

    return 0;
}
