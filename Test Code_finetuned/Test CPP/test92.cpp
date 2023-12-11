import os
import sqlite3

class FileManager:
    def __init__(self):
        self.db_connection = None
        self.workspace_id = None
        self.working_dir = None

    def initializeSource(self, db_path, workspace_id):
        self.db_connection = sqlite3.connect(db_path)
        self.workspace_id = workspace_id

    def setWorkingDir(self, working_dir):
        self.working_dir = working_dir

    def loadFiles(self, where_clause):
        cursor = self.db_connection.cursor()
        cursor.execute(f"SELECT * FROM files WHERE {where_clause}")
        return cursor.fetchall()

    def insertOrUpdateLocalFile(self, file_id, workspace_id, file_content):
        file_path = os.path.join(self.working_dir, str(file_id))
        with open(file_path, 'w') as file:
            file.write(file_content)

    def removeLocalFile(self, file_id):
        file_path = os.path.join(self.working_dir, str(file_id))
        if os.path.exists(file_path):
            os.remove(file_path)

    def insertDBFile(self, file_name):
        cursor = self.db_connection.cursor()
        cursor.execute(f"INSERT INTO files (name, workspace_id) VALUES (?,?)", (file_name, self.workspace_id))
        self.db_connection.commit()
        return cursor.lastrowid

    def updateDBFile(self, file_id, file_name, workspace_id):
        cursor = self.db_connection.cursor()
        cursor.execute(f"UPDATE files SET name =?, workspace_id =? WHERE id =?", (file_name, workspace_id, file_id))
        self.db_connection.commit()