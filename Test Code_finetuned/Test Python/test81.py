def myPow(x, n):
    if n == 0:
        return 1
    elif n < 0:
        return 1 / myPow(x, -n)
    elif n % 2 == 0:
        return myPow(x*x, n//2)
    else:
        return x * myPow(x*x, (n-1)//2)