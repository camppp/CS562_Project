#include <iostream>
#include <string>
#include <xyz/openbmc_project/Control/Power/ACPIPowerState.hpp>
#include <xyz/openbmc_project/Software/Activation.hpp>

using namespace std;
using namespace xyz::openbmc_project::Control::Power;
using namespace xyz::openbmc_project::Software::Activation;

int main() {
    // Connect to the D-Bus system bus
    auto bus = sdbusplus::bus::new_default();

    // Initialize the necessary interfaces for power management
    auto power_iface = ACPIPowerState::create(bus, "/xyz/openbmc_project/control/power/acpi_power_state");
    auto activation_iface = Activation::create(bus, "/xyz/openbmc_project/software/activation");

    // Query the current power state of the system
    auto power_state = power_iface->get_power_state();
    cout << "Current power state: " << power_state << endl;

    // If the current power state is "off", attempt to activate the software
    if (power_state == "off") {
        auto activation_result = activation_iface->activate();
        if (activation_result.first == "success") {
            cout << "Software activation successful" << endl;
        } else {
            cout << "Software activation failed" << endl;
        }
    }

    // Once the software activation is successful, change the power state to "on"
    if (power_state == "on") {
        power_iface->set_power_state("on");
        cout << "Power state changed to 'on'" << endl;
    }

    return 0;
}
