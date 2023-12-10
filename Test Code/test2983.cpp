python
def calculate_loan_payment(rate, nper, pv):
    try:
        payment = (rate * pv) / (1 - (1 + rate)**-nper)
        return round(payment, 2)
    except ZeroDivisionError:
        return "Error: Division by zero"
    except (TypeError, ValueError):
        return "Error: Invalid input"
