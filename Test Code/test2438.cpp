python
import re

def parseKeywords(code_snippet):
    keyword_pattern = r'{"(.*?)",\s+(T_\w+),\s+(SYNTAX_\w+(\s*\|\s*SYNTAX_\w+)*)}'
    matches = re.findall(keyword_pattern, code_snippet)

    keywords_map = {}
    for match in matches:
        keyword = match[0]
        token = match[1]
        syntax_properties = match[2]
        keywords_map[keyword] = {"token": token, "syntax_properties": syntax_properties}

    return keywords_map

# Example usage
code_snippet = '''
      {"asinh",                  T_ASINH,        SYNTAX_PROPERTY | SYNTAX_NEW},
#line 39 "keywords.gperf"
      {"assert",			T_ASSERT,	SYNTAX_NEW},
      {""},
#line 56 "keywords.gperf"
      {"simulate",               T_SIMULATE,     SYNTAX_PROPERTY},
#line 95 "keywords.gperf"
      {"tanh",                   T_TANH,         SYNTAX_PROPERTY | SYNTAX_NEW},
#line 97 "keywords.gperf"
      {"acosh",                  T_ACOSH,        SYNTAX_PROPERTY | SYNTAX_NEW},
#line 52 "keywords.gperf"
      {"scalar",			T_SCALAR,	SYNTAX_OLD | SYNTAX_NEW | SYNTAX_PROPERTY},
      {""},
#line 67 "keywords.gperf"
'''
result = parseKeywords(code_snippet)
print(result)
