python
def sort_paths(paths):
    for i in range(len(paths)):
        for j in range(i+1, len(paths)):
            if paths[i] > paths[j]:
                paths[i], paths[j] = paths[j], paths[i]
    return paths
