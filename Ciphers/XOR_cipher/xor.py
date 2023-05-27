import sys
import binascii

def encode(message: bytearray, key: bytearray) -> bytearray :
    encoded = bytearray()
    key_len = len(key)
    for i in range(0, len(message)):
        encoded.append(message[i] ^ key[i%(key_len)])
    
    return encoded


message = b'<MESSAGE_TO_REPLACE>'
key = b'<KEY_TO_REPLACE>'

result = encode(bytearray(message), bytearray(key))

result_formated = "\\x"+"\\x".join(str(binascii.hexlify(result, '-'))[1:].replace("'", "").split('-'))

print(len(result), " bytes\n", result_formated, "\n", bytes(result).decode('utf-8'), sep='')
