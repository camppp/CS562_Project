python
def generate_font(file_name):
    font = {}
    with open(file_name, 'r') as file:
        n, m = map(int, file.readline().split())
        for _ in range(n):
            char = file.readline().strip()
            bitmap = [file.readline().strip() for _ in range(m)]
            font[char] = bitmap
    return font
