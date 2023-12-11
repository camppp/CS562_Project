#include "WriteChecker.h"
#include <activemq/transport/inactivity/InactivityMonitor.h>
#include <decaf/lang/System.h>
#include <decaf/lang/exceptions/NullPointerException.h>

using namespace activemq;
using namespace activemq::transport;
using namespace activemq::transport::inactivity;
using namespace decaf;
using namespace decaf::util;

class WriteChecker {
private:
    InactivityMonitor* monitor;

public:
    WriteChecker(InactivityMonitor* monitor) : monitor(monitor) {
        if (monitor == nullptr) {
            throw decaf::lang::exceptions::NullPointerException(__FILE__, __LINE__, "InactivityMonitor cannot be null");
        }
    }

    void checkWrite() {
        try {
            if (monitor->isInactive()) {
                throw decaf::lang::exceptions::NullPointerException(__FILE__, __LINE__, "Inactivity detected");
            }
        } catch (const std::exception& e) {
            // Handle the exception
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }
};