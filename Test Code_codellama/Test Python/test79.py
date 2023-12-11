import numpy as np

def average_attribute_value(file_path: str, attribute_name: str) -> float:
    with EdfReader(file_path) as reader:
        data = reader.read_data()
        attribute_values = data[attribute_name]
        return np.mean(attribute_values)