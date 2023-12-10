bool parse_args(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Invalid arguments" << std::endl;
        return false;
    }

    if (argc == 4) {
        std::cout << "Processing 4 arguments" << std::endl;
        return true;
    }

    if (argc > 4) {
        std::cout << "Processing more than 4 arguments" << std::endl;
        return true;
    }

    if (argc == 5 && std::string(argv[4]) == "verbose") {
        std::cout << "Processing 5 arguments in verbose mode" << std::endl;
        return true;
    }

    std::cout << "Invalid arguments" << std::endl;
    return false;
}
