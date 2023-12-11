import hashlib

def getDigest(input, algorithm='md5'):
    if algorithm.lower() =='md5':
        hash_object = hashlib.md5(input.encode())
    elif algorithm.lower() =='sha256':
        hash_object = hashlib.sha256(input.encode())
    elif algorithm.lower() =='sha512':
        hash_object = hashlib.sha512(input.encode())
    else:
        return "Invalid algorithm. Please choose from'md5','sha256', or'sha512'."

    return {
        'algorithm': algorithm,
        'digest': hash_object.hexdigest()
    }