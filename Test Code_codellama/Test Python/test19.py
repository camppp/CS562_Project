def validate_domain(domain: str, allowed_hosts: list) -> bool:
    if not domain:
        return False
    if '*' in allowed_hosts:
        return True
    for host in allowed_hosts:
        if host == domain or host.endswith('.' + domain):
            return True
    return False