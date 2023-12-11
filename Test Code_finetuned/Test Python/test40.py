import random

def generate_cat_name():
    while True:
        name = input("Please enter your desired cat name: ")
        if len(name) > 26 or len(name) == 0:
            print("Your cat name is not valid. It should be under 26 characters in length and not be empty.")
        elif not name.isalpha():
            print("Your cat name is not valid. It should not contain any special characters or numbers.")
        else:
            print("Your cat name is: " + name)
            break

def generate_negative_reply():
    negative_replies = ["I'm sorry, but your cat name is not valid.",
                        "I'm afraid that's not a valid cat name.",
                        "Your cat name is not acceptable. Please try again.",
                        "Your cat name is not suitable. Please choose another one."]
    return random.choice(negative_replies)

generate_cat_name()