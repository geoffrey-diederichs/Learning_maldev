import sys
import binascii

def encode(message: bytearray) -> bytearray :
    encoded = bytearray([message.pop(0)])
    for i in range(0, len(message)):
        encoded.append(message[i] ^ encoded[i])

    return encoded

def decode(message: bytearray) -> bytearray:
    message.reverse()
    decoded = bytearray()
    for i in range(0, len(message)-1):
        decoded.append(message[i] ^ message[i+1])
    decoded.append(message[len(message)-1])
    decoded.reverse()

    return decoded


message = b'<MESSAGE_TO_REPLACE>'

if len(sys.argv) > 1:
    if sys.argv[1] == "0":
        result = encode(bytearray(message))
    elif sys.argv[1] == "1":
        result = decode(bytearray(message))
    else:
        quit()
else:
    quit()

result_formated = "\\x"+"\\x".join(str(binascii.hexlify(result, '-'))[1:].replace("'", "").split('-'))

print(len(result), " bytes\n", result_formated, "\n", bytes(result).decode('utf-8'), sep='')
