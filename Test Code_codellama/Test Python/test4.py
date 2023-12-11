# Import the necessary libraries
import RPi.GPIO as GPIO
import time

# Initialize the pin and relay mapping based on the provided comment in the code snippet
pin = 12
relay = 1

# Define a function to toggle the relay, simulating the action of dispensing a product
def toggle_relay():
    GPIO.output(pin, GPIO.HIGH)
    time.sleep(0.5)
    GPIO.output(pin, GPIO.LOW)

# Provide a user interface to prompt the user for input to trigger the dispenser
print("Welcome to the women's restroom dispenser!")
print("Please enter 'dispense' to trigger the dispenser.")

# Loop indefinitely, waiting for user input
while True:
    input = input("> ")
    if input == "dispense":
        toggle_relay()
        print("Dispenser triggered!")
    else:
        print("Invalid input. Please")