import pandas as pd

def get_population(popDF, stateName):
    """
    Retrieve the population of a specific state from the given DataFrame.

    Args:
    popDF: A pandas DataFrame containing population data with state names as the index.
    stateName: A string representing the name of the state for which population needs to be retrieved.

    Returns:
    The population of the specified state.
    """
    return popDF.loc[stateName, 'Pop']