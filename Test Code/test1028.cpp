python
def isPalindrome(num: int) -> bool:
    if num < 0:  # If the number is negative, it cannot be a palindrome
        return False
    original_num = num
    reverse_num = 0
    while num > 0:
        digit = num % 10
        reverse_num = reverse_num * 10 + digit
        num = num // 10
    return original_num == reverse_num
