import logging

def admin_cm_log(log, pack):
    def decorator(func):
        def wrapper(*args, **kwargs):
            if log:
                logging.info(f"Input: {args}, {kwargs}")
            result = func(*args, **kwargs)
            if pack:
                logging.info(f"Output: {result}")
            return result
        return wrapper
    return decorator

@admin_cm_log(True, True)
def multiple_change_quota(cm_response, **data):
    # Change quota as described by the data parameter
    pass