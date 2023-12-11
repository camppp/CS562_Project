def extract_package_info(config: dict, info: str) -> str:
    if info in config:
        return config[info]
    else:
        return "Information not found"