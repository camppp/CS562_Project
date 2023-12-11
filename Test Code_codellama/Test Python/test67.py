def extract_version(classifiers, language):
    for classifier in classifiers:
        if classifier.startswith(f'Programming Language :: {language} ::'):
            return classifier.split(' :: ')[2]
    return 'Language not found'