#include <CQChartsVariant.h>

QString processPlotModelValue(CQChartsPlot *plot, int visibleColumnInd, bool &ok) {
  // Retrieve the value from the plot model
  QVariant value = plot->modelValue(visibleColumnInd, ok);

  // Check if the retrieval was successful
  if (!ok) {
    return "Error: Failed to retrieve value from plot model";
  }

  // Check if the value can be converted to a boolean
  bool boolValue;
  if (!CQChartsVariant::toBool(value, boolValue, ok)) {
    return "Error: Invalid value for boolean";
  }

  // Perform the specific operation based on the boolean value
  if (boolValue) {
    // Do something if the value is true
  }
  else {
    // Do something if the value is false
  }

  return ""; // No error
}
