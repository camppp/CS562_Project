#include <iostream>

int main(int argc, char* argv[]) {
    std::string uri;

    if (argc == 2) {
        // Store the URI from argv[1] in the variable uri
        uri = argv[1];

        // Perform echo client logic here (e.g., send a request to the server and echo the response)
        // ...

        // Echo the received response
        std::cout << "Response from " << uri << ": [Received response content]" << std::endl;
    } else {
        // Display usage message for incorrect number of arguments
        std::cout << "Usage: " << argv[0] << " test_url" << std::endl;
    }

    return 0;
}
