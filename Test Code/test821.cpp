python
def process_queries(input_file):
    with open(input_file, 'r') as file:
        n, m = map(int, file.readline().split())
        repositories = {}
        for _ in range(n):
            repo, stars = file.readline().split()
            repositories[repo] = int(stars)

        queries = [list(map(int, file.readline().split())) for _ in range(m)]

        for repo, stars in repositories.items():
            print(repo, stars)

        for query in queries:
            total_stars = sum(stars for stars in repositories.values() if query[0] <= stars <= query[1])
            print(total_stars)

# Example usage
process_queries('input.txt')
