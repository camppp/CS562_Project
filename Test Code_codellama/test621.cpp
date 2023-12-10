#include "qos_handler.hpp"

class QoSHandlerFactory {
public:
    QoSHandler* createQoSHandler(QoSLevel level) {
        switch (level) {
            case QoSLevel::BestEffort:
                return new BestEffortQoSHandler();
            case QoSLevel::AtLeastOnce:
                return new AtLeastOnceQoSHandler();
            case QoSLevel::ExactlyOnce:
                return new ExactlyOnceQoSHandler();
            default:
                throw std::invalid_argument("Invalid QoS level");
        }
    }
};
