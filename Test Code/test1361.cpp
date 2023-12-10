python
import struct

def custom_serialize_deserialize(config_params: dict) -> bytes:
    serialized_data = b''
    for key, value in config_params.items():
        serialized_data += struct.pack('i', value)
    return serialized_data

def custom_deserialize(byte_stream: bytes) -> dict:
    config_params = {}
    num_integers = len(byte_stream) // struct.calcsize('i')
    for i in range(num_integers):
        value = struct.unpack('i', byte_stream[i*4:(i+1)*4])[0]
        config_params[f'param{i}'] = value
    return config_params
