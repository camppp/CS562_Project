def extractParts(parts: List[str]) -> List[str]:
    if len(parts) < WAC_CERTIFY_MANDATORY_PART_HIGH_COUNT:
        return []
    major = parts[WAC_CERTIFY_MANDATORY_PART_MAJOR_INDEX]
    minor = parts[WAC_CERTIFY_MANDATORY_PART_MINOR_INDEX]
    micro = parts[WAC_CERTIFY_MANDATORY_PART_MICRO_INDEX]
    return [major, minor, micro]
