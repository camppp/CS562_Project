from fastapi import Depends, HTTPException, status
from fastapi.security import APIKeyHeader

JWT_TOKEN_PREFIX = "Bearer"

def authrization_heder_token(api_key: str = Depends(APIKeyHeader(name="Authorization"))):
    try:
        token_prefix, token = api_key.split(" ")
    except ValueError:
        raise HTTPException(status_code=status.HTTP_403_FORBIDDEN, detail="invalid authorization header")

    if token_prefix != JWT_TOKEN_PREFIX:
        raise HTTPException(status_code=status.HTTP_403_FORBIDDEN, detail="unsupported authorization type")

    # Validate the token format
    if not token.startswith("eyJ"):
        raise HTTPException(status_code=status.HTTP_403_FORBIDDEN, detail="invalid token format")
