def get_log_level_constant(log_level_name):
    if log_level_name == "logLevelDebug":
        return 0
    elif log_level_name == "logLevelInfo":
        return 3
    elif log_level_name == "logLevelWarning":
        return 4
    elif log_level_name == "logLevelError":
        return 5
    elif log_level_name == "logLevelOff":
        return 6
    else:
        return -1
