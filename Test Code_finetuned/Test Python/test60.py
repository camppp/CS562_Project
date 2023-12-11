class ProgrammingLanguage:
    def __init__(self, lang_name, lang_code):
        self.lang_name = lang_name
        self.lang_code = lang_code

    def get_info(self):
        return f"Language: {self.lang_name}, Code: {self.lang_code}"