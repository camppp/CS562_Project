def findSameReleaseTimes(m_ulPunkReleaseSameTime: List[List[int]], NOTAVAIL: int) -> List[int]:
    # Initialize an empty list to store the indices of the contexts with the same release times
    same_release_times = []

    # Iterate over the rows of the 2D array
    for i in range(len(m_ulPunkReleaseSameTime)):
        # Get the release times for the current context
        release_times = m_ulPunkReleaseSameTime[i]

        # Check if all the release times are the same
        if all(release_times[j] == release_times[0] for j in range(len(release_times))):
            # If all the release times are the same, add the index of the current context to the list of same release times
            same_release_times.append(i)

    return same_release_times
