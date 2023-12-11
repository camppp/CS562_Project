class User:
    def __init__(self, name):
        self.name = name

class Folder:
    def __init__(self, name):
        self.name = name
        self.users = []

    def assign_user(self, user):
        self.users.append(user)

class FileSystem:
    def __init__(self):
        self.folders = {}

    def create_folder(self, user, folderName):
        if not isinstance(user, User):
            raise ValueError("user must be an instance of User class")
        if not isinstance(folderName, str):
            raise ValueError("folderName must be a string")
        if folderName in self.folders:
            raise ValueError("Folder with the same name already exists")

        new_folder = Folder(folderName)
        new_folder.assign_user(user)
        self.folders[folderName] = new_folder