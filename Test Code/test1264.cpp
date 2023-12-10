python
# Open the file in read mode to read the integers
with open("file.txt", "r") as file:
    integers = list(map(int, file.read().split()))

# Calculate the squares of the integers and write them back to the file
with open("file.txt", "w") as file:
    squared_integers = [str(num**2) for num in integers]
    file.write(" ".join(squared_integers))

# Calculate the sum of the squared integers
sum_of_squares = sum([num**2 for num in integers])

# Output the sum of the squared integers
print("Sum of squared integers:", sum_of_squares)
