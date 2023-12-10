python
def unicode_to_code_points(input_str):
    code_points = []
    i = 0
    while i < len(input_str):
        if input_str[i] == '\\' and i + 1 < len(input_str) and input_str[i + 1] == 'u':
            code_point = int(input_str[i + 2:i + 6], 16)
            code_points.append(code_point)
            i += 6
        else:
            code_points.append(ord(input_str[i]))
            i += 1
    return code_points

input_str = "Hello, World!"  # Replace with any Unicode string
code_points = unicode_to_code_points(input_str)
print(code_points)
