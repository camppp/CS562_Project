def calculate_loan_payment(rate, nper, pv):
    # Check for invalid input
    if rate <= 0 or nper <= 0 or pv <= 0:
        raise ValueError("Invalid input")

    # Calculate the payment
    payment = (rate * pv) / (1 - (1 + rate)**-nper)

    # Round the payment to two decimal places
    payment = round(payment, 2)

    return payment
