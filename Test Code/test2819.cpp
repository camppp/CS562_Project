python
from typing import List

def extractNamespaceHierarchy(code: str) -> List[str]:
    namespaces = []
    current_namespace = ""
    indent_level = 0

    for line in code.split('\n'):
        if "namespace" in line:
            indent_level = line.count('{') - line.count('}')
            namespace_name = line.split()[1].strip('{}')
            if indent_level == 0:
                current_namespace = namespace_name
            else:
                current_namespace += "::" + namespace_name
            namespaces.append(current_namespace)

    return namespaces
