import requests
import json

def handle_http_response(r):
    if r.status_code in [200, 201]:
        return r.json()
    else:
        raise IOError(r.text)

# Assuming r is an HTTP response object
r = requests.get('https://api.example.com/data')

try:
    result = handle_http_response(r)
    print(result)  # JSON content of the response
except IOError as e:
    print(e)  # Error message from the response