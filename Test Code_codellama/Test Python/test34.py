def generate_sql_statements(operations):
    # Write your code here
    sql_statements = []
    for op in operations:
        if op[0] == 'migrate':
            sql_statements.append('APPLY MIGRATION \'' + op[1] + '\'')
        else:
            sql_statements.append('REVERT MIGRATION \'' + op[1] + '\'')
    return sql_statements


operations = [ ('migrate', '0001_initial'), ('rollback', '0002_auto_20170417_0012'), ('migrate', '0003_auto_20170417_0012'), ('migrate', '0004_auto_20170417_0012'), ('rollback', '0005_auto_20170417_0012'), ]
print(generate_sql_statements(operations))