#include <iostream>
#include <string>
#include "CQChartsVariant.h"  // Assuming the necessary header file

std::string processPlotModelValue(Plot* plot_, int visibleColumnInd, bool ok) {
    auto value = plot_->modelValue(visibleColumnInd, ok);

    if (!ok) {
        return "Error: Retrieval of plot model value failed.";
    } else {
        bool boolValue;
        if (CQChartsVariant::toBool(value, boolValue, ok)) {
            if (ok) {
                // Perform specific operation based on the boolean value
                if (boolValue) {
                    // Perform operation for true value
                    return "Operation performed for true value.";
                } else {
                    // Perform operation for false value
                    return "Operation performed for false value.";
                }
            } else {
                return "Error: Invalid boolean value retrieved.";
            }
        } else {
            return "Error: Value cannot be converted to boolean.";
        }
    }
}

int main() {
    // Example usage
    Plot* plot = new Plot();  // Assuming Plot class exists
    int columnInd = 0;
    bool ok = true;
    std::cout << processPlotModelValue(plot, columnInd, ok) << std::endl;
    return 0;
}
