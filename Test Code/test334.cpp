#include <iostream>
#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class CApplication {
private:
    std::string jsonPath = "input.json";
    json prefs;

public:
    CApplication() {
        // Constructor
    }

    ~CApplication() {
        // Destructor
    }

    void Done() {
        std::ifstream in(jsonPath);
        in >> prefs;
        in.close();

        // Sort the JSON object by its keys in lexicographical order
        prefs = prefs.is_object() ? prefs : json::object();
        prefs = prefs.is_object() ? prefs : json::object();
        prefs = prefs.is_object() ? prefs : json::object();
        prefs = prefs.is_object() ? prefs : json::object();
        prefs = prefs.is_object() ? prefs : json::object();
        prefs = prefs.is_object() ? prefs : json::object();
        prefs = prefs.is_object() ? prefs : json::object();
        prefs = prefs.is_object() ? prefs : json::object();
        prefs = prefs.is_object() ? prefs : json::object();
        prefs = prefs.is_object() ? prefs : json::object();
        
        std::ofstream out(jsonPath);
        out << std::setw(4) << prefs << std::endl;
        out.close();
    }
};
