import psycopg2

class PostgresConnection:
    def __init__(self, username, password, database, host, port):
        self.username = username
        self.password = password
        self.database = database
        self.host = host
        self.port = port
        self.connection = None

    def connect(self):
        try:
            self.connection = psycopg2.connect(
                host=self.host,
                port=self.port,
                dbname=self.database,
                user=self.username,
                password=self.password
            )
        except psycopg2.OperationalError as e:
            raise ConnectionError(f"Failed to connect to PostgreSQL database: {e}")

    def execute_query(self, query):
        try:
            with self.connection.cursor() as cursor:
                cursor.execute(query)
                result = cursor.fetchall()
                return result
        except psycopg2.ProgrammingError as e:
            raise QueryExecutionError(f"Failed to execute query: {e}")

    def close_connection(self):
        try:
            self.connection.close()
        except psycopg2.OperationalError as e:
            raise ConnectionError(f"Failed to close PostgreSQL connection: {e}")