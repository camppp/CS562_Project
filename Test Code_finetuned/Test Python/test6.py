import RPi.GPIO as GPIO

# Pin and relay mapping
pin_mapping = {
    17: 1,
}

# Setup GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)

def dispense():
    # Toggle the relay
    GPIO.output(17, GPIO.HIGH)
    print("Dispensing product")
    GPIO.output(17, GPIO.LOW)

def main():
    while True:
        user_input = input("Press Enter to dispense a product, or 'q' to quit: ")
        if user_input.lower() == 'q':
            break
        dispense()

    # Cleanup GPIO
    GPIO.cleanup()

if __name__ == "__main__":
    main()