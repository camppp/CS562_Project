sum = 0
while True:
    try:
        num = int(input("Enter an integer: "))
        if num % 2 == 0:
            sum += num
    except ValueError:
        break
print("The sum of the even numbers is", sum)