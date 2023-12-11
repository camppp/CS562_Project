class RepositoryReference:
    @staticmethod
    def for_repo_obj(repo_obj):
        return f"Reference to repository object: {repo_obj.name}"

class Repository:
    def __init__(self, name):
        self.name = name

def get_repository_reference(repo_obj):
    return RepositoryReference.for_repo_obj(repo_obj)

repo = Repository("example_repo")
reference = get_repository_reference(repo)
print(reference)  # Output: Reference to repository object: example_repo