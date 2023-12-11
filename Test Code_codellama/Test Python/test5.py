# Initialize the pin and relay mapping based on the provided comment in the code snippet
pin_number = 12
relay_number = 1

# Implement a function to toggle the relay, simulating the action of dispensing a product
def toggle_relay():
    # Toggle the relay
    GPIO.output(pin_number, GPIO.HIGH)
    time.sleep(0.5)
    GPIO.output(pin_number, GPIO.LOW)

# Provide a user interface to prompt the user for input to trigger the dispenser
print("Welcome to the dispenser control system!")
print("Please enter 'dispense' to trigger the dispenser:")

# Loop until the user enters 'dispense'
while True:
    user_input = input("> ")
    if user_input == "dispense":
        # Toggle the relay to simulate the action of dispensing a product
        toggle_relay()
        print("Product dispensed!")
        break
    else:
        print("Invalid input. Please enter 'dispense' to trigger the dispenser:")