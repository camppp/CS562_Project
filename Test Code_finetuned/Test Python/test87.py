# Step 1: Take two integer inputs, n1 and n2, from the user.
n1 = int(input("Enter the first number: "))
n2 = int(input("Enter the second number: "))

# Step 2: Calculate the sum of n1 and n2 and store it in a variable s.
s = n1 + n2

# Step 3: Calculate the product of n1 and n2 and store it in a variable m.
m = n1 * n2

# Step 4: Calculate the division of n1 by n2 and store it in a variable d.
# Check if n2 is not zero to avoid division by zero error.
if n2!= 0:
    d = n1 / n2
else:
    d = "undefined"

# Step 5: Calculate the integer division of n1 by n2 and store it in a variable di.
# Check if n2 is not zero to avoid division by zero error.
if n2!= 0:
    di = n1 // n2
else:
    di = "undefined"

# Step 6: Calculate the exponentiation of n1 to the power of n2 and store it in a variable e.
e = n1 ** n2

# Step 7: Print the results in the specified format.
print(f"A soma é {s}, o produto é {m} e a divisão é {d} Divisão inteira {di} e potência {e}")