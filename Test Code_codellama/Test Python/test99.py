def extract_top_level_domain(url):
    domain = url.split('.')[-2]
    return domain