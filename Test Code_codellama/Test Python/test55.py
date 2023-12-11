import numpy as np

def normalize_flux(flux, cont, window):
    # Calculate the median of each row within the specified window
    medians = np.median(flux, axis=1, window=window)

    # Normalize the flux data by dividing each element by the corresponding median value
    normalized_flux = flux / medians

    # Return the normalized flux data
    return normalized_flux

# Define the flux and continuum data
flux = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
cont = np.array([1, 2, 3])

# Define the window size
window = 2

# Normalize the flux data
normalized_flux = normalize_flux(flux, cont, window)

# Print the normalized flux data
print(normalized_flux)