python
def WriteVersion(maxVersion):
    with open('version.txt', 'w') as file:
        file.write(f'MaxVersion={maxVersion}')
