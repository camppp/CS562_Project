import base64

def validatePayload(text, maxSize):
    try:
        decoded_payload = base64.b64decode(text)
    except base64.InvalidBase64Error as e:
        raise ValidationException(e.message)

    if len(decoded_payload) > maxSize:
        raise ValidationException(f"Payload exceeded max size = {maxSize} bytes")