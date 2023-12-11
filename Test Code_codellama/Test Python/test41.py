def extract_package_info(config: dict, info: str) -> str:
    if info not in config:
        return "Information not found"
    return config[info]