python
import re

# Given code snippet
code_snippet = '<reponame>ITBear/GpNetwork<gh_stars>0\n#include "GpHttpServerNodeSocketTaskFactory.hpp"\n#include "GpHttpServerNodeSocketTask.hpp"\n\nnamespace GPlatform {'

# Regular expression pattern to extract repository information
pattern = r'<reponame>([\w\/]+)<gh_stars>(\d+)'

# Extracting repository information using regular expression
match = re.search(pattern, code_snippet)

if match:
    repository_name = match.group(1)
    owner_name = repository_name.split('/')[0]
    stars = int(match.group(2))

    # Displaying the extracted repository information
    print("Repository Name:", repository_name)
    print("Owner/Organization Name:", owner_name)
    print("Number of Stars:", stars)
else:
    print("No repository information found in the code snippet.")
