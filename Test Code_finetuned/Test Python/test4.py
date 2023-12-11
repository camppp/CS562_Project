from fastapi import Depends, HTTPException, status
from fastapi.security import APIKeyHeader
import jwt

JWT_TOKEN_PREFIX = "Bearer"
SECRET_KEY = "your_secret_key"  # replace with your actual secret key
ALGORITHM = "HS256"  # replace with your actual algorithm

def authrization_heder_token(api_key: str = Depends(APIKeyHeader(name="Authorization"))) -> str:
    try:
        token_prefix, token = api_key.split(" ")
    except ValueError:
        raise HTTPException(status_code=status.HTTP_403_FORBIDDEN, detail="invalid authorization header")

    if token_prefix!= JWT_TOKEN_PREFIX:
        raise HTTPException(status_code=status.HTTP_403_FORBIDDEN, detail="unsupported authorization type")

    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
    except jwt.ExpiredSignatureError:
        raise HTTPException(status_code=status.HTTP_401_UNAUTHORIZED, detail="Token has expired")
    except jwt.InvalidTokenError:
        raise HTTPException(status_code=status.HTTP_403_FORBIDDEN, detail="Invalid token")

    return token