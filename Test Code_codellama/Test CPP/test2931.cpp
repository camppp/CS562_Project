class Task {
    public:
        // Define member variables for the task type and the timestamp
        string type;
        string timestamp;

        // Define a constructor to initialize the task type and timestamp
        Task(string type, string timestamp) {
            this->type = type;
            this->timestamp = timestamp;
        }
};

class L2MdApi {
    private:
        // Define member variables for the heartbeat and warning timestamps
        string heartbeatTimestamp;
        string warningTimestamp;

        // Define a method to process the incoming task
        void processTask(Task task) {
            // Check the task type and perform the necessary actions
            if (task.type == "heartbeat") {
                // Update the heartbeat timestamp
                heartbeatTimestamp = task.timestamp;
            } else if (task.type == "warning") {
                // Update the warning timestamp
                warningTimestamp = task.timestamp;
            }
        }

    public:
        // Define a method to process the incoming heartbeat and warning tasks
        void processHeartBeatWarning(Task task) {
            // Call the processTask method to process the incoming task
            processTask(task);
        }
};
