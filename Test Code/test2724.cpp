#include <string>

std::string getNextFocus(const std::string& currentFocus) {
  if (currentFocus == "mHullNumberSelector") {
    return "mServerIpSelector";
  } else if (currentFocus == "mServerIpSelector") {
    return "mConnectButton";
  } else {
    return "mHullNumberSelector";
  }
}
