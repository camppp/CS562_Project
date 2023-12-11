class Font:
    def __init__(self, name='Arial', size=12, bold=False):
        self.name = name
        self.size = size
        self.bold = bold

    def get_name(self):
        return self.name

    def set_name(self, name):
        self.name = name

    def get_size(self):
        return self.size

    def set_size(self, size):
        self.size = size

    def get_bold(self):
        return self.bold

    def set_bold(self, bold):
        self.bold = bold