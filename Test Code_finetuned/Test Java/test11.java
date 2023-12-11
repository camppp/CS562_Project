import numpy as np
from scipy.stats import norm

def calculateOptionPrices(strikes, S_t, X, r, t, sigma):
    d1 = (np.log(S_t / X) + (r + 0.5 * sigma ** 2) * t) / (sigma * np.sqrt(t))
    d2 = d1 - sigma * np.sqrt(t)
    res = S_t * norm.cdf(d1) - X * np.exp(-r * t) * norm.cdf(d2)
    return res