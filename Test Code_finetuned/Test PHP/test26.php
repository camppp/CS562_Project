def createSchema(backend_type, schema_definitions):
    backend_commands = {
        "mysql": "CREATE TABLE {table} ({columns})",
        "postgresql": "CREATE TABLE {table} ({columns})",
        "sqlite": "CREATE TABLE {table} ({columns})"
    }

    sql_commands = []

    for table, columns in schema_definitions.items():
        columns_str = ', '.join(columns)
        sql_command = backend_commands[backend_type].format(table=table, columns=columns_str)
        sql_commands.append(sql_command)

    return sql_commands

# Test the function
schema_definitions = {
    "users": ["id INT PRIMARY KEY", "name VARCHAR(100)", "email VARCHAR(100)"],
    "posts": ["id INT PRIMARY KEY", "title VARCHAR(100)", "content TEXT", "user_id INT", "FOREIGN KEY (user_id) REFERENCES users(id)"]
}

backend_type = "mysql"
sql_commands = createSchema(backend_type, schema_definitions)

for command in sql_commands:
    print(command)