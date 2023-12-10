python
import math

def calculate_f(x, y, z, pi):
    pi2 = pi ** 2
    f_2 = (1 + 3 * pi2) * math.cos(z) * math.sin(x) * math.sin(y)
    return f_2

# Example usage
x_input = 1.5  # Replace with actual input value for x
y_input = 2.0  # Replace with actual input value for y
z_input = 0.8  # Replace with actual input value for z
pi_input = math.pi  # Replace with actual value of pi
result = calculate_f(x_input, y_input, z_input, pi_input)
print("Value of f[2] =", result)
