#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

map<string, tuple<string, int>> parse_xml_input(string xml_input) {
    map<string, tuple<string, int>> port_info;

    // Create an XML parser
    tinyxml2::XMLDocument doc;
    doc.Parse(xml_input.c_str());

    // Get the root element
    tinyxml2::XMLElement* root = doc.RootElement();

    // Iterate over the child elements of the root element
    for (tinyxml2::XMLElement* child = root->FirstChildElement(); child; child = child->NextSiblingElement()) {
        // Check if the child element is a port
        if (child->Name() == "port") {
            // Get the port ID
            string port_id = child->Attribute("id");

            // Get the precision
            string precision = child->Attribute("precision");

            // Get the dimensions
            int dimensions = 0;
            for (tinyxml2::XMLElement* dim = child->FirstChildElement("dim"); dim; dim = dim->NextSiblingElement("dim")) {
                dimensions += stoi(dim->GetText());
            }

            // Add the port information to the map
            port_info[port_id] = make_tuple(precision, dimensions);
        }
    }

    return port_info;
}

int main() {
    // Read the XML input from a file
    ifstream ifs("input.xml");
    string xml_input((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());

    // Parse the XML input
    map<string, tuple<string, int>> port_info = parse_xml_input(xml_input);

    // Print the port information
    for (const auto& port : port_info) {
        cout << "Port " << port.first << " has precision " << port.second.get<0>() << " and dimensions " << port.second.get<1>() << endl;
    }

    return 0;
}
