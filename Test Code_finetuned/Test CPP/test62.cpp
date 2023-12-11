def get_user_input():
    while True:
        try:
            n = int(input("Enter a non-negative integer: "))
            if n < 0:
                print("Error: Please enter a non-negative integer.")
            else:
                return n
        except ValueError:
            print("Error: Please enter a valid integer.")

def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n-1)

n = get_user_input()
print(f"The factorial of {n} is {factorial(n)}")