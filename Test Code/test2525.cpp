python
import numpy as np

def calculate_runge_kutta_coefficients(order):
    # Initialize the Butcher tableau coefficients
    A = np.zeros((order, order))
    b = np.zeros(order)
    b_star = np.zeros(order)
    c = np.zeros(order)

    # Define the coefficients based on the order of the Runge-Kutta method
    if order == 1:
        A[0, 0] = 0
        b[0] = 1
        b_star[0] = 1
        c[0] = 0
    else:
        # Define the coefficients for higher order methods
        # (Example coefficients for a specific method, replace with actual coefficients based on the research paper)
        # A, b, b_star, and c should be calculated based on the specific Runge-Kutta method
        # Replace the following coefficients with the actual coefficients from the research paper
        A = np.array([[0, 0],
                      [1, 0]])
        b = np.array([0.5, 0.5])
        b_star = np.array([1, 0])
        c = np.array([0, 1])

    return A, b, b_star, c
