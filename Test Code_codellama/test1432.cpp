#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> extract_network_info(map<string, string> event_dict) {
    map<string, string> network_info;

    // Check if the event dictionary contains the keys for the decision and shunting networks
    if (event_dict.find("decision_network") != event_dict.end() &&
        event_dict.find("shunting_network") != event_dict.end()) {
        // Add the decision and shunting networks to the network info map
        network_info["decision_network"] = event_dict["decision_network"];
        network_info["shunting_network"] = event_dict["shunting_network"];
    }

    return network_info;
}

int main() {
    map<string, string> event = {
        {"name", "model"},
        {"decision_network", "DN_network"},
        {"shunting_network", "SM_network"},
        {"decision_pre_evolve", "DN_EVOLED"},
        {"shunting_pre_evolve", "SM_EVOLED"}
    };

    map<string, string> network_info = extract_network_info(event);

    for (auto& network : network_info) {
        cout << network.first << ": " << network.second << endl;
    }

    return 0;
}
