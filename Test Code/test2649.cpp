python
def custom_comparison(a_Meta1, a_Meta2):
    # Handle special cases
    if a_Meta1 is None or a_Meta2 is None:
        return False
    if isinstance(a_Meta1, str) and isinstance(a_Meta2, str):
        if a_Meta1.lower() == a_Meta2.lower():
            return False
    if isinstance(a_Meta1, int) and isinstance(a_Meta2, int):
        if a_Meta1 == 0 and a_Meta2 == 0:
            return False

    # Raw comparison
    return a_Meta1 < a_Meta2
