import random

def roll_dice():
    return random.randint(1, 6), random.randint(1, 6)

def main():
    print("Welcome to the Dice Rolling Game!")
    print("Press Enter to roll the dice or type 'exit' to quit.")
    while True:
        user_input = input()
        if user_input.lower() == "exit":
            print("Thanks for playing! Goodbye!")
            exit(0)
        elif user_input == "":
            dice1, dice2 = roll_dice()
            print(f"You rolled: {dice1} and {dice2}")
            print("Roll again? (Press Enter to roll or type 'exit' to quit)")

if __name__ == "__main__":
    main()