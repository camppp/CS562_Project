python
import re

def parseIl2CppTypeDefinitionSizes(code_snippet):
    result = {}
    match = re.search(r'extern const Il2CppTypeDefinitionSizes (\w+) = { (.*), (.*), (.+), (.+) };', code_snippet)
    if match:
        result["name"] = match.group(1)
        result["size"] = match.group(2)
        result["type"] = match.group(3)
    return result

# Test the function with the provided example
code_snippet = "extern const Il2CppTypeDefinitionSizes g_typeDefinitionSize3693 = { sizeof (GdipImageCodecInfo_t2577501090)+ sizeof (Il2CppObject), sizeof(GdipImageCodecInfo_t2577501090 ), 0, 0 };"
print(parseIl2CppTypeDefinitionSizes(code_snippet))
