def validate_domain(domain: str, allowed_hosts: list) -> bool:
    # Split the domain into its subdomains
    domain_parts = domain.split('.')

    # Iterate over the allowed hosts
    for allowed_host in allowed_hosts:
        # If the allowed host is a wildcard, return True
        if allowed_host == '*':
            return True

        # If the allowed host is a domain name, compare it with the given domain
        if allowed_host == domain:
            return True

        # If the allowed host is a subdomain, check if the given domain is a subdomain of the allowed host
        if allowed_host.startswith('*.'):
            allowed_host_parts = allowed_host[2:].split('.')
            if len(domain_parts) >= len(allowed_host_parts) and domain_parts[-len(allowed_host_parts):] == allowed_host_parts:
                return True

    # If no match is found, return False
    return False