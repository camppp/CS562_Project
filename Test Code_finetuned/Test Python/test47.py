class CircularDependencyError(Exception):
    pass

class MissingDependencyError(Exception):
    pass

def apply_migrations(migrations):
    # Create a dictionary to store the migrations
    migration_dict = {m.name: m for m in migrations}

    # Create a set to store the migrations that have been applied
    applied_migrations = set()

    # Create a function to apply a migration
    def apply_migration(migration):
        # Check if the migration has already been applied
        if migration.name in applied_migrations:
            return

        # Check for circular dependencies
        if migration.name in applied_migrations:
            raise CircularDependencyError(f"Circular dependency detected for migration {migration.name}")

        # Apply the dependencies
        for dependency in migration.dependencies:
            if dependency not in migration_dict:
                raise MissingDependencyError(f"Missing dependency {dependency} for migration {migration.name}")
            apply_migration(migration_dict[dependency])

        # Apply the operations
        for operation in migration.operations:
            operation.apply()

        # Mark the migration as applied
        applied_migrations.add(migration.name)

    # Apply the migrations
    for migration in migrations:
        apply_migration(migration)