def extract_function_name(input_string):
    start_index = input_string.find('"')
    end_index = input_string.find('"', start_index + 1)
    if start_index == -1 or end_index == -1:
        return ""
    else:
        return input_string[start_index + 1:end_index]
