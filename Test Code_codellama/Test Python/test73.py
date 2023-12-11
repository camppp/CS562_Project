def extract_field_info(operations):
    field_info = []
    for operation in operations:
        model_name = operation.model_name
        field_name = operation.name
        field_type = operation.field.__class__.__name__
        max_length = None
        if hasattr(operation.field, 'max_length'):
            max_length = operation.field.max_length
        field_info.append({
            'model_name': model_name,
            'field_name': field_name,
            'field_type': field_type,
            'max_length': max_length,
        })
    return field_info