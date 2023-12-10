python
def get_log_level_constant(log_level_name):
    log_level_constants = {
        "logLevelAll": 0,
        "logLevelTrace": 1,
        "logLevelDebug": 2,
        "logLevelInfo": 3,
        "logLevelWarn": 4,
        "logLevelError": 5,
        "logLevelFatal": 6,
        "logLevelOff": 7
    }
    return log_level_constants.get(log_level_name, -1)
