def get_migration_order(migrations):
   # Create a dictionary to store the dependencies of each migration
   migration_dependencies = {}
   for migration in migrations:
       migration_dependencies[migration] = migration.dependencies

   # Create a list to store the ordered migrations
   ordered_migrations = []

   # Iterate over the migrations and add them to the ordered list if they have no dependencies
   for migration in migrations:
       if not migration_dependencies[migration]:
           ordered_migrations.append(migration)

   # Iterate over the migrations and add them to the ordered list if they have dependencies that have already been added
   for migration in migrations:
       if migration_dependencies[migration]:
           for dependency in migration_dependencies[migration]:
               if dependency in ordered_migrations:
                   ordered_migrations.append(migration)

   return ordered_migrations