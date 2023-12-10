python
def linear_congruential_generator(mk, mj, ma):
    a = 1664525
    c = 1013904223
    m = 2**32
    mk = mk * a + c
    mk = mk % m
    return mk
