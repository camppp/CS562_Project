def strip_suffix(original: str, suffix: str) -> str:
    if original.endswith(suffix):
        return original[:-len(suffix)]
    else:
        return original