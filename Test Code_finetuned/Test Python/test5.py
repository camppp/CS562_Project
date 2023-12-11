
def extract_license_info(license_text: str) -> dict:
    lines = license_text.splitlines()
    license_type = lines[1].strip()
    permissions = []
    limitations = []
    start_permissions = False
    start_limitations = False
    for line in lines:
        if "WITHOUT WARRANTIES OR CONDITIONS OF ANY" in line:
            start_permissions = True
        elif "limitations" in line:
            start_permissions = False
            start_limitations = True
        elif start_permissions:
            permissions.append(line.strip())
        elif start_limitations:
            limitations.append(line.strip())
    return {
        "license_type": license_type,
        "permissions": permissions,
        "limitations": limitations
    }