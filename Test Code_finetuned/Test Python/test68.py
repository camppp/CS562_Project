def process_input(input_str):
    result = {}
    if not input_str:
        result["code"] = 400
        result["msg"] = "Empty input string"
        return result
    try:
        if "." in input_str:
            float_val = float(input_str)
            result["input_type"] = "float"
        else:
            int_val = int(input_str)
            result["input_type"] = "integer"
    except ValueError as e:
        result["input_type"] = "string"
    except Exception as e:
        result["code"] = 401
        result["msg"] = str(e)
    return result