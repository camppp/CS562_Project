import base64

class ValidationException(Exception):
    pass

def validatePayload(text, maxSize):
    try:
        decoded_payload = base64.b64decode(text)
    except Exception as e:
        raise ValidationException(str(e))

    if len(decoded_payload) > maxSize:
        raise ValidationException(f"Payload exceeded max size = {maxSize} bytes")

try:
    validatePayload("SGVsbG8gV29ybGQ=", 10)
except ValidationException as e:
    print(e)

try:
    validatePayload("SGVsbG8gV29ybGQ=", 5)
except ValidationException as e:
    print(e)