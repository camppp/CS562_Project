python
class Database:
    def __init__(self, database):
        self.m_database = database

    def insert(self, key, value):
        self.m_database[key] = value

    def get(self, key):
        return self.m_database.get(key)

    def delete(self, key):
        del self.m_database[key]
