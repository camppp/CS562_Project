import os

class ConfigurationManager:
    def __init__(self, directory):
        self.directory = directory

    def patch(self, setting_name, new_value):
        cache = os.path.join(self.directory, 'config.cache')
        with open(cache, 'r') as file:
            content = file.readlines()

        for i in range(len(content)):
            if setting_name in content[i]:
                content[i] = f"{setting_name}={new_value}\n"

        with open(cache, 'w') as file:
            file.writelines(content)