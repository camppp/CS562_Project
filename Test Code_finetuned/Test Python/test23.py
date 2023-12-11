def get_migration_order(migrations):
    # Build a dependency graph
    graph = {m: set(m.dependencies) for m in migrations}

    # Perform a DFS to find the order
    visited = set()
    order = []

    def dfs(migration):
        if migration not in visited:
            visited.add(migration)
            for dependency in graph[migration]:
                dfs(dependency)
            order.append(migration)

    for migration in migrations:
        dfs(migration)

    # Reverse the order to get the correct order
    return order[::-1]