python
def maxPensAndPencils(T, p, f, cs, cw, s, w):
    result = []
    for i in range(T):
        max_pens = min(s[i] // cs[i], p[i])  # Calculate maximum pens within budget
        max_pencils = min(w[i] // cw[i], f[i])  # Calculate maximum pencils within budget
        result.append([max_pens, max_pencils])
    return result
