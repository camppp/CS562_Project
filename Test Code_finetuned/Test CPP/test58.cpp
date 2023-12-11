def find_unique_substrings(A, wsize, lsize):
    substrings = set()
    for i in range(len(A) - wsize * lsize + 1):
        chunk = A[i:i+wsize*lsize]
        for j in range(lsize):
            substrings.add(chunk[j*wsize:(j+1)*wsize])
    return len(substrings)

A = "abracadabra"
wsize = 2
lsize = 3
print(find_unique_substrings(A, wsize, lsize))  # Output: 6