python
def main():
    try:
        with open("input.txt", "r") as file:
            text = file.read().lower()  # Read the text file and convert to lowercase for case-insensitive comparison
            if not text.strip():  # Check if the file is empty
                print("The file is empty.")
                return

        while True:
            phrase = input("Enter a phrase (or 'exit' to quit): ").lower()
            if phrase == "exit":
                break
            count = text.count(phrase)  # Count the occurrences of the phrase in the text
            if count > 0:
                print(f"The phrase '{phrase}' appears {count} time(s) in the text file.")
            else:
                print(f"The phrase '{phrase}' is not found in the text file.")

    except FileNotFoundError:
        print("The file 'input.txt' is not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
