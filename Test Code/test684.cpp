python
import re

# Read the file and extract the years from each notice
with open('copyright_notices.txt', 'r') as file:
    content = file.read()
    years = re.findall(r'(\d{4})-(\d{4})', content)

# Determine the range of years covered by the notices
all_years = [int(year) for start, end in years for year in (start, end)]
earliest_year = min(all_years)
latest_year = max(all_years)

# Output the earliest and latest years found
print(f"Earliest year: {earliest_year}")
print(f"Latest year: {latest_year}")
