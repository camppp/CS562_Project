python
import math

def calculate_KL_divergence(mu_prior_i: float, var_prior_i: float, mu_posterior_i: float, var_posterior_i: float, mu_prior_j: float, var_prior_j: float, mu_posterior_j: float, var_posterior_j: float) -> float:
    kl_divergence_i = 0.5 * (math.log(var_posterior_i / var_prior_i) + (var_prior_i + (mu_prior_i - mu_posterior_i)**2) / var_posterior_i - 1)
    kl_divergence_j = 0.5 * (math.log(var_posterior_j / var_prior_j) + (var_prior_j + (mu_prior_j - mu_posterior_j)**2) / var_posterior_j - 1)
    return kl_divergence_j - kl_divergence_i
