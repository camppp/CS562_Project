python
import hashlib

def calculate_sha256_and_size(input_string):
    # Calculate the SHA-256 hash
    sha256_hash = hashlib.sha256(input_string.encode()).hexdigest()

    # Calculate the size in bytes
    size_in_bytes = len(input_string.encode('utf-8'))

    return sha256_hash, size_in_bytes

# Example usage
input_string = "hello world"
sha256_hash, size_in_bytes = calculate_sha256_and_size(input_string)
print(f"Input String: {input_string}")
print(f"SHA-256 Hash: {sha256_hash}")
print(f"Size in Bytes: {size_in_bytes}")
