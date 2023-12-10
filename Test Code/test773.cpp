python
from typing import List

def findSameReleaseTimes(m_ulPunkReleaseSameTime: List[List[int]], NOTAVAIL: int) -> List[int]:
    same_release_times = []
    for i in range(len(m_ulPunkReleaseSameTime)):
        if all(m_ulPunkReleaseSameTime[i][j] != NOTAVAIL and m_ulPunkReleaseSameTime[i][j] == m_ulPunkReleaseSameTime[i][0] for j in range(len(m_ulPunkReleaseSameTime[i]))):
            same_release_times.append(i)
    return same_release_times
