class TestProcessor {
public:
    TestProcessor(const std::string& config) {
        // Parse the configuration string and extract the prescale factor
        std::stringstream ss(config);
        std::string line;
        while (std::getline(ss, line)) {
            if (line.find("prescaleFactor") != std::string::npos) {
                std::stringstream ss2(line);
                ss2 >> prescaleFactor;
            }
        }
    }

    bool modulePassed(int event) {
        // Simulate the behavior of the test processor based on the prescale factor
        if (event % prescaleFactor == 0) {
            return true;
        } else {
            return false;
        }
    }

private:
    int prescaleFactor;
};
