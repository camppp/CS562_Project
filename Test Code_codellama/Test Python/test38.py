import random

def generate_cat_name():
    while True:
        name = input("Enter a cat name: ")
        if len(name) > 26:
            print("Sorry, the name is too long. Please try again.")
        elif any(char.isdigit() or char.isspace() for char in name):
            print("Sorry, the name contains special characters or numbers. Please try again.")
        elif name == "":
            print("Sorry, the name cannot be empty. Please try again.")
        else:
            return name

def main():
    print("Welcome to the cat name generator!")
    while True:
        name = generate_cat_name()
        print(f"Your cat's name is {name}!")

if __name__ == "__main__":
    main()