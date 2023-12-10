python
from typing import List, Dict, Union

def formatContactInfo(contacts: List[Dict[str, Union[str, int]]]) -> List[str]:
    formatted_contacts = []
    for contact in contacts:
        formatted_contact = f"Contact information for {contact['name']}:\n- Telephone: {contact['telephone']}\n- Index: {contact['index']}"
        formatted_contacts.append(formatted_contact)
    return formatted_contacts

# Test the function
contacts = [
    {"name": "Alice", "telephone": "123-456-7890", "index": 1},
    {"name": "Bob", "telephone": "987-654-3210", "index": 2}
]
formatted_output = formatContactInfo(contacts)
print(formatted_output)
