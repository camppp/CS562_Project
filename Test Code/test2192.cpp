#include <string>
#include <sstream>
#include <vector>
#include <iostream>

class TestProcessor {
public:
    struct Config {
        int prescaleFactor;
        std::string otherParameters;
    };

    TestProcessor(const std::string& configString) {
        std::istringstream iss(configString);
        std::string line;
        while (std::getline(iss, line, '\n')) {
            if (line.find("offset=") != std::string::npos) {
                config.prescaleFactor = std::stoi(line.substr(7));
            } else {
                config.otherParameters += line + "\n";
            }
        }
    }

    bool modulePassed() {
        if (failCount < config.prescaleFactor) {
            failCount++;
            return false;
        } else {
            failCount = 0;
            return true;
        }
    }

private:
    Config config;
    int failCount = 0;
};

// Unit tests
void testModulePassed() {
    std::string baseConfig = "otherParam1=value1\notherParam2=value2";
    TestProcessor::Config config{5, baseConfig};
    TestProcessor tester(config);

    // Test with prescaleFactor = 5
    for (int i = 0; i < 7; i++) {
        if (i % 5 == 4) {
            assert(tester.modulePassed() == true);
        } else {
            assert(tester.modulePassed() == false);
        }
    }
}

int main() {
    testModulePassed();
    return 0;
}
