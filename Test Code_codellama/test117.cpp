class IdentifiedObject {
public:
    void parse(Parser& p, const std::string& f) {
        // Parse the content of the file or data source
        while (p.more_content()) {
            // Extract the next content
            std::string content = p.next_content();

            // Process the content
            // ...
        }
    }
};

class Parser {
public:
    bool more_content() {
        // Check if there is more content to process
        // ...
    }

    std::string next_content() {
        // Extract the next content
        // ...
    }
};
