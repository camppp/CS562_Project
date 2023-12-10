python
class InvalidArgument(Exception):
    pass

def parse_key_value(input_string):
    key_value_map = {}
    cur_key = ""
    cur_val = ""
    reading_key = True
    escaped = False

    for c in input_string:
        if c == '=' and not escaped:
            if cur_key == "":
                raise InvalidArgument("Bad KV spec empty key")
            reading_key = False
        elif c == ',' and not escaped:
            if cur_key == "":
                raise InvalidArgument("Bad KV spec empty key")
            if cur_key in key_value_map:
                raise InvalidArgument("Bad KV spec duplicated key")
            key_value_map[cur_key] = cur_val
            cur_key = ""
            cur_val = ""
            reading_key = True
        elif c == '\\':
            escaped = True
        else:
            if reading_key:
                cur_key += c
            else:
                cur_val += c
            escaped = False

    if cur_key == "":
        raise InvalidArgument("Bad KV spec empty key")
    if cur_key in key_value_map:
        raise InvalidArgument("Bad KV spec duplicated key")
    key_value_map[cur_key] = cur_val

    return key_value_map

# Test the function
try:
    input_str = "name=John,age=30,city=New York"
    result = parse_key_value(input_str)
    print(result)  # Output: {'name': 'John', 'age': '30', 'city': 'New York'}

    invalid_input_str = "name=John,age=30,city=New York,"
    result = parse_key_value(invalid_input_str)  # This should raise an exception
except InvalidArgument as e:
    print(e)  # Output: Bad KV spec empty key
