def generate_config_file(local_url, remote_url, site_title, site_description, copy_rst, disqus_shortname):
    config_file = f"""# Blog Engine Configuration
local_url = "{local_url}"
remote_url = "{remote_url}"
site_title = "{site_title}"
site_description = "{site_description}"
copy_rst = {str(copy_rst).lower()}
disqus_shortname = "{disqus_shortname}"
"""
    return config_file