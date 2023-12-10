python
total_read = 0  # Initialize the total amount read
while True:
    read = int(input("Enter the input value: "))  # Read the input value
    if read < 0:  # Check if the specific condition is met (e.g., negative input)
        break  # Exit the loop if the condition is met
    total_read += read  # Accumulate the total amount read

print("Total amount read:", total_read)  # Output the total amount read
