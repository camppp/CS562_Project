def process_migration_operations(operations, models):
    result = {}
    for operation in operations:
        if operation[0] == 'AlterField':
            model_name = operation[1]
            field_name = operation[2]
            if model_name in result:
                result[model_name].append(field_name)
            else:
                result[model_name] = [field_name]
    return result