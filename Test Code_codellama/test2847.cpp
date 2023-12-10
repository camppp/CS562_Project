def find_failing_script(scripts: List[str]) -> int:
    for i, script in enumerate(scripts):
        if script(i) != 0:
            return i
    return -1
