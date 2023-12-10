def find_first(collection, condition, default):
    for element in collection:
        if condition(element):
            return element
    return default
