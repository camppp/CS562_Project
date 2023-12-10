#include <iostream>
#include <string>
#include <vector>

#define LAYOUT(x) std::vector<std::string> layout = {x};
#define SX_SEPARATOR "--------------------"

class EventDataParser {
private:
    std::string data;
    std::vector<std::string> layout;

public:
    EventDataParser(std::string data) : data(data) {}

    std::string getLayout() {
        return layout[0];
    }

    std::string shiftString() {
        std::string result;
        for (int i = 0; i < layout.size(); i++) {
            if (layout[i] == "sx::String") {
                result = data.substr(0, data.find(" "));
                data = data.substr(data.find(" ") + 1);
                return result;
            }
        }
        return "";
    }

    int shiftInt() {
        int result;
        for (int i = 0; i < layout.size(); i++) {
            if (layout[i] == "sx::Int") {
                result = std::stoi(data.substr(0, data.find(" ")));
                data = data.substr(data.find(" ") + 1);
                return result;
            }
        }
        return 0;
    }
};
