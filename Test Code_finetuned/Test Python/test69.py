class Accession:
    def __init__(self, name, files, **kwargs):
        self.name = name
        self.files = list(files)
        self.metadata = kwargs

    def get_files(self):
        return self.files

    def get_metadata(self):
        return self.metadata