#include <string>
#include <vector>
#include <memory>

class MessageHandler {
public:
    MessageHandler(std::string setPose_name, std::string setCustomPose_name, std::string emergency_name, std::shared_ptr<Queue> queue) {
        // Subscribe to the set pose node
        setPoseSubscriber = queue->subscribe(setPose_name, &MessageHandler::processSetPoseMessage, this);

        // Subscribe to the set custom pose node
        setCustomPoseSubscriber = queue->subscribe(setCustomPose_name, &MessageHandler::processCustomPoseMessage, this);

        // Subscribe to the emergency signal node
        emergencySignalSubscriber = queue->subscribe(emergency_name, &MessageHandler::processEmergencySignal, this);
    }

    ~MessageHandler() {
        // Unsubscribe from the set pose node
        setPoseSubscriber.unsubscribe();

        // Unsubscribe from the set custom pose node
        setCustomPoseSubscriber.unsubscribe();

        // Unsubscribe from the emergency signal node
        emergencySignalSubscriber.unsubscribe();
    }

    void processSetPoseMessage(const Pose& pose) {
        // Process the received pose message and perform the necessary actions based on the received pose data
        // ...
    }

    void processCustomPoseMessage(const CustomPose& customPose) {
        // Process the received custom pose message and handle the custom pose data appropriately
        // ...
    }

    void processEmergencySignal(const EmergencySignal& signal) {
        // Handle the emergency signal received and take appropriate actions to ensure the safety of the robotic arm
        // ...
    }

private:
    std::shared_ptr<Queue> queue;
    Subscriber<Pose> setPoseSubscriber;
    Subscriber<CustomPose> setCustomPoseSubscriber;
    Subscriber<EmergencySignal> emergencySignalSubscriber;
};
