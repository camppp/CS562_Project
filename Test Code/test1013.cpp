python
def SerializePayload(payload):
    query_string = '&'.join(f"{key}={urllib.parse.quote(value)}" for key, value in payload.items())
    return query_string
