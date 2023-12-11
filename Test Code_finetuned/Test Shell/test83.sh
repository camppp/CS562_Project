def get_unstable_increment(unstable_version: str) -> int:
    # Split the version tag by '.'
    version_parts = unstable_version.split('.')
    
    # The unstable increment is the last part of the version tag
    unstable_increment = int(version_parts[-1])
    
    return unstable_increment