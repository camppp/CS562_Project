python
def extract_function_name(input_string):
    start_index = input_string.find('"') + 1
    end_index = input_string.find('"', start_index)
    if start_index != -1 and end_index != -1:
        return input_string[start_index:end_index]
    else:
        return ""
