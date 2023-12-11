class RepositoryReference:
    @staticmethod
    def for_repo_obj(repo_obj):
        return repo_obj
    
def get_repository_reference(repo_obj):
    return RepositoryReference.for_repo_obj(repo_obj)

repo = Repository("example_repo")
reference = get_repository_reference(repo)
print(reference) # Output: Reference to repository object: example_repo