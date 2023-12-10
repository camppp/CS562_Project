python
import json

def validate_activity_data(json_obj):
    if "ActivityJoinDetail" in json_obj and "ActivityData" in json_obj["ActivityJoinDetail"]:
        if isinstance(json_obj["ActivityJoinDetail"]["ActivityData"], str):
            return True
    return False

# Example usage
json_data = '''
{
    "ActivityJoinDetail": {
        "ActivityData": "some_data"
    }
}
'''
parsed_json = json.loads(json_data)
print(validate_activity_data(parsed_json))  # Output: True
