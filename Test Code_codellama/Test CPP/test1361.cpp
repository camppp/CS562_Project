python
def custom_serialize_deserialize(config_params: dict) -> bytes:
    # Serialize the dictionary of hardware configuration parameters
    # into a byte stream using a custom serialization format
    serialized_bytes = b''
    for key, value in config_params.items():
        serialized_bytes += key.encode() + b'=' + str(value).encode() + b'\n'
    return serialized_bytes

def custom_deserialize(byte_stream: bytes) -> dict:
    # Deserialize the byte stream into a dictionary of hardware configuration parameters
    # using a custom deserialization format
    config_params = {}
    for line in byte_stream.split(b'\n'):
        key, value = line.split(b'=')
        config_params[key.decode()] = int(value.decode())
    return config_params
