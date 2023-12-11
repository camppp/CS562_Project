import re

def extractCSSInfo(css):
    css_classes = re.findall(r'\.([^{]+)\s*{([^}]*)}', css)
    css_info = {}
    for class_name, properties in css_classes:
        properties = re.findall(r'([^:]+):([^;]+);', properties)
        css_info[class_name.strip()] = {prop.strip(): value.strip() for prop, value in properties}
    return css_info