// Include necessary headers
#include "best_effort_qos_handler.hpp"
#include "at_least_once_qos_handler.hpp"
#include "exactly_once_qos_handler.hpp"

// Define the QoSHandlerFactory class
class QoSHandlerFactory {
public:
    // Create a QoS handler based on the specified QoS level
    QoSHandler* createQoSHandler(QoSLevel level) {
        switch (level) {
            case QoSLevel::BestEffort:
                return new BestEffortQoSHandler();
            case QoSLevel::AtLeastOnce:
                return new AtLeastOnceQoSHandler();
            case QoSLevel::ExactlyOnce:
                return new ExactlyOnceQoSHandler();
            default:
                return nullptr; // Handle unknown QoS level
        }
    }
};
