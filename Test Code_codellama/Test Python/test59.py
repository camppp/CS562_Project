def extract_uri_components(uri):
    if not uri.startswith('ccnx:'):
        raise ValueError('Invalid URI')
    components = uri[6:].split('/')
    return components
    
# Test case 1:
assert extract_uri_components('ccnx:/apple/banana/cherry/durian') == ['apple', 'banana', 'cherry', 'durian']
# Test case 2:
assert extract_uri_components('ccnx:/apple/banana/cherry') == ['apple', 'banana', 'cherry']
# Test case 3:
assert extract_uri_components('ccnx:/apple/banana') == ['apple', 'banana']
# Test case 4:
assert extract_uri_components('ccnx:/apple') == ['apple']
# Test case 5:
assert extract_uri_components('ccnx:') == []