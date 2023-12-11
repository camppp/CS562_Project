import numpy as np

def concatenate_nested(*args):
    # Check if the first argument is a dictionary
    if isinstance(args[0][0], dict):
        # Concatenate all the dictionaries in the nested lists
        concatenated_dict = {}
        for nested_list in args:
            for element in nested_list:
                if isinstance(element, dict):
                    concatenated_dict.update(element)
        return concatenated_dict
    # Check if the first argument is a numpy array
    elif isinstance(args[0][0], np.ndarray):
        # Concatenate all the numpy arrays in the nested lists
        concatenated_array = np.concatenate(args[0])
        for nested_list in args[1:]:
            concatenated_array = np.concatenate((concatenated_array, np.concatenate(nested_list)))
        return concatenated_array
    # Check if the first argument is a list and the first element is a numpy array
    elif isinstance(args[0][0], list) and isinstance(args[0][0][0], np.ndarray):
        # Concatenate all the numpy arrays in the nested lists
        concatenated_array = np.concatenate(args[0][0])
        for nested_list in args[1:]:
            concatenated_array = np.concatenate((concatenated_array, np.concatenate(nested_list[0])))
        return concatenated_array
    else:
        raise ValueError("Invalid input type")