import re

def extractJobId(html_code: str) -> str:
    pattern = r"modal_add_edit_job/(\d+)"
    match = re.search(pattern, html_code)
    if match:
        return match.group(1)
    else:
        return ""