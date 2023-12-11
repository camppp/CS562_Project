import re

# Open the text file
with open("sample_text.txt", "r") as f:
    text = f.read()

# Create a regular expression to match the words of interest
pattern = r"(DAMAGES|SERVICES|PROFITS|BUSINESS)"

# Use the regular expression to count the occurrences of each word
damages_count = len(re.findall(pattern, text, re.IGNORECASE))
services_count = len(re.findall(pattern, text, re.IGNORECASE))
profits_count = len(re.findall(pattern, text, re.IGNORECASE))
business_count = len(re.findall(pattern, text, re.IGNORECASE))

# Print the counts of each word
print(f"DAMAGES: {damages_count}")
print(f"SERVICES: {services_count}")
print(f"PROFITS: {profits_count}")
print(f"BUSINESS: {business_count}")
