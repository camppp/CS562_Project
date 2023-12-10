python
from typing import List

def applyAssignments(JB: List[float], w: List[float], p: List[float], x: List[float], dwdx: List[float]) -> List[float]:
    for i in range(len(w)):
        JB[2 + i*10] = -w[i]
    for i in range(len(p)):
        JB[2 + (i+1)*10] = -p[0]*p[1]
    JB[3 + 1*10] = 1.0
    JB[3 + 2*10] = 1.0
    JB[3 + 3*10] = p[0]
    JB[4 + 0*10] = -x[4]*dwdx[1]
    return JB
