from collections import deque

class CircularDependencyError(Exception):
    pass

class MissingDependencyError(Exception):
    pass

def apply_migrations(migrations):
    # Create a queue to store the migrations to be applied
    queue = deque()

    # Add the first migration to the queue
    queue.append(migrations[0])

    # Loop through the migrations
    while queue:
        # Get the next migration from the queue
        migration = queue.popleft()

        # Check if the migration has any dependencies
        if migration.dependencies:
            # Check if the dependencies are satisfied
            for app_label, migration_name in migration.dependencies:
                if app_label not in migrations or migration_name not in migrations[app_label]:
                    raise MissingDependencyError(f"Missing dependency: {app_label}.{migration})