def sparse_cosine_similarity(vector1, vector2):
    if not vector1 or not vector2:
        return 0
    dot_product = 0
    norm1 = 0
    norm2 = 0
    for i in vector1:
        dot_product += vector1[i] * vector2.get(i, 0)
        norm1 += vector1[i] ** 2
    for i in vector2:
        if i not in vector1:
            norm2 += vector2[i] ** 2
    return dot_product / (norm1 ** 0.5 * norm2 ** 0.5)