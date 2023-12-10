#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string uri;

    if (argc == 2) {
        uri = argv[1];
    } else if (argc > 2) {
        std::cout << "Usage: echo_client test_url" << std::endl;
        return 1;
    }

    // Your implementation here

    return 0;
}
