def process_message_template(template, placeholder_values):
    for placeholder, value in placeholder_values.items():
        template = template.replace("{{$" + placeholder + "}}", value)
    return template