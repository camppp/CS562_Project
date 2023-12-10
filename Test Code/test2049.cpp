python
class Logger:
    def __init__(self):
        self.error_logs = []
        self.warning_logs = []
        self.info_logs = []

    def LogError(self, message):
        self.error_logs.append(message)

    def LogWarning(self, message):
        self.warning_logs.append(message)

    def LogInfo(self, message):
        self.info_logs.append(message)

    def GetLogs(self, log_type):
        if log_type == "error":
            return self.error_logs
        elif log_type == "warning":
            return self.warning_logs
        elif log_type == "info":
            return self.info_logs
        else:
            return []

# Example usage
logger = Logger()
logger.LogError("Couldn't not call ServerScriptEvent.")
logger.LogWarning("Connection timeout.")
logger.LogInfo("Request processed successfully.")
print(logger.GetLogs("error"))  # Output: ["Couldn't not call ServerScriptEvent."]
print(logger.GetLogs("warning"))  # Output: ["Connection timeout."]
print(logger.GetLogs("info"))  # Output: ["Request processed successfully."]
