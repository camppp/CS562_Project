def process_migration_operations(operations: list, models: list) -> dict:
    altered_fields = {}
    for model in models:
        altered_fields[model[0]] = []
    for operation in operations:
        if isinstance(operation, migrations.AlterField):
            altered_fields[operation.model_name].append(operation.name)
    return altered_fields