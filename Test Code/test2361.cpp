#include <iostream>
#include <vector>
#include <string>
#include <tinyxml2.h>

struct USDevice {
    std::string name;
    std::string manufacturer;
    int serialNumber;
    struct Probe {
        std::string type;
        std::string frequency;
    } probe;
};

std::vector<USDevice> parseUSDevices(const std::string& filename) {
    std::vector<USDevice> devices;

    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error loading XML file: " << filename << std::endl;
        return devices;
    }

    tinyxml2::XMLElement* root = doc.FirstChildElement("USDevices");
    if (!root) {
        std::cerr << "Missing root element 'USDevices' in XML file" << std::endl;
        return devices;
    }

    for (tinyxml2::XMLElement* deviceElem = root->FirstChildElement("Device"); deviceElem; deviceElem = deviceElem->NextSiblingElement("Device")) {
        USDevice device;
        device.name = deviceElem->FirstChildElement("Name")->GetText();
        device.manufacturer = deviceElem->FirstChildElement("Manufacturer")->GetText();
        device.serialNumber = std::stoi(deviceElem->FirstChildElement("SerialNumber")->GetText());

        tinyxml2::XMLElement* probeElem = deviceElem->FirstChildElement("Probe");
        if (probeElem) {
            device.probe.type = probeElem->FirstChildElement("Type")->GetText();
            device.probe.frequency = probeElem->FirstChildElement("Frequency")->GetText();
        }

        devices.push_back(device);
    }

    return devices;
}
