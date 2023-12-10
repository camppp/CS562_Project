def calculate_KL_divergence(mu_prior_i: float, var_prior_i: float, mu_posterior_i: float, var_posterior_i: float, mu_prior_j: float, var_prior_j: float, mu_posterior_j: float, var_posterior_j: float) -> float:
    # Calculate the KL divergence between the posterior and prior distributions for object i
    KL_i = 0.5 * (mu_posterior_i - mu_prior_i)**2 / var_prior_i + 0.5 * (var_posterior_i - var_prior_i)**2 / var_prior_i

    # Calculate the KL divergence between the posterior and prior distributions for object j
    KL_j = 0.5 * (mu_posterior_j - mu_prior_j)**2 / var_prior_j + 0.5 * (var_posterior_j - var_prior_j)**2 / var_prior_j

    # Return the KL divergence between the posterior and prior distributions for object j, given the observation o_j > o_i
    return KL_j - KL_i
