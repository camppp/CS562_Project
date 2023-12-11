import requests
import json

def admin_cm_log(log, pack):
    def decorator(func):
        def wrapper(*args, **kwargs):
            if log:
                print(f"Input to function {func.__name__}: {args}, {kwargs}")

            result = func(*args, **kwargs)

            if log:
                print(f"Output from function {func.__name__}: {result}")

            if pack:
                # Assuming the function `multiple_change_quota` takes `cm_response` and `**data` as arguments
                cm_response, data = args[0], kwargs
                # Send a request to change quota
                response = requests.post(
                    "http://your-api-endpoint.com/change-quota",
                    data=json.dumps(data),
                    headers={"Authorization": f"Bearer {cm_response.token}"}
                )
                print(f"Request to change quota sent with status code: {response.status_code}")

            return result
        return wrapper
    return decorator

@admin_cm_log(log=True, pack=True)
def multiple_change_quota(cm_response, **data):
    # Implementation of the function to change quota
    pass