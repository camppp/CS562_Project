class Table:
    def __init__(self, schema: str, table_name: str):
        self.schema = schema
        self.table_name = table_name

    def __eq__(self, other):
        return self.schema == other.schema and self.table_name == other.table_name

    def __hash__(self):
        return hash((self.schema, self.table_name))