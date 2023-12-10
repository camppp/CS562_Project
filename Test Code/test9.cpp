#include <iostream>

int main(int argc, char* argv[]) {
    std::string uri;

    if (argc == 2) {
        uri = argv[1];
        // Implement the logic to echo the response from the server at the given URI
        // ...
    } else if (argc > 2) {
        std::cout << "Usage: `echo_client test_url`" << std::endl;
    }

    return 0;
}
