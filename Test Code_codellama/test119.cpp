#include <iostream>
#include <vector>
#include <string>

class CTSTestData {
public:
    CTSTestData() {}
    ~CTSTestData() {
        for (auto& suite : suites_) {
            delete suite;
        }
        suites_.clear();
        machineName_.clear();
    }

    void AddSuite(const std::string& name, const std::vector<std::string>& tests) {
        suites_.push_back(new TestSuite(name, tests));
    }

    size_t GetSuiteCount() const {
        return suites_.size();
    }

    const std::string& GetMachineName() const {
        return machineName_;
    }

    void SetMachineName(const std::string& name) {
        machineName_ = name;
    }

private:
    struct TestSuite {
        std::string name;
        std::vector<std::string> tests;

        TestSuite(const std::string& name, const std::vector<std::string>& tests) : name(name), tests(tests) {}
    };

    std::vector<TestSuite*> suites_;
    std::string machineName_;
};
