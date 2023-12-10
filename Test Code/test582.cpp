python
def calculateCrossSectionalArea(Hm, Hpf, fa_int, L, D):
    if D == 0:
        return 0
    else:
        area = (Hm + Hpf + fa_int) * L / D
        return area
