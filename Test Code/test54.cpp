python
class Folder:
    def __init__(self, name, user):
        self.name = name
        self.user = user

class FileSystem:
    def __init__(self):
        self.folders = []

    def create_folder(self, user, folderName):
        if not folderName:
            raise ValueError("Folder name cannot be empty")

        new_folder = Folder(folderName, user)
        self.folders.append(new_folder)
