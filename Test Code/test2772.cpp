python
def count_license_keywords(license_text: str) -> dict:
    # Convert the license text to lowercase to make the search case-insensitive
    license_text_lower = license_text.lower()
    
    # Initialize counts for each keyword to zero
    keyword_counts = {
        "software": 0,
        "warranties": 0,
        "conditions": 0,
        "limitations": 0
    }
    
    # Count the occurrences of each keyword in the license text
    for keyword in keyword_counts:
        keyword_counts[keyword] = license_text_lower.count(keyword)
    
    return keyword_counts
