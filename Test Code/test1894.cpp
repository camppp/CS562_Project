python
def groupNumbers(nums):
    even_numbers = [num for num in nums if num % 2 == 0]
    odd_numbers = [num for num in nums if num % 2 != 0]
    return [even_numbers, odd_numbers]

def main():
    input_str = input("Enter a list of integers separated by spaces: ")
    nums = list(map(int, input_str.split()))
    grouped_lists = groupNumbers(nums)
    print("Even numbers:", grouped_lists[0])
    print("Odd numbers:", grouped_lists[1])

if __name__ == "__main__":
    main()
