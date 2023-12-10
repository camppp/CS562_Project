import json

def validate_json(json_data):
    # Check if the "ActivityData" field exists in the JSON object
    if "ActivityJoinDetail" in json_data and "ActivityData" in json_data["ActivityJoinDetail"]:
        # Check if the value of the "ActivityData" field is a string
        if isinstance(json_data["ActivityJoinDetail"]["ActivityData"], str):
            return True
        else:
            return False
    else:
        return False
