import sys
import binascii

def encode(code: bytearray) -> bytearray :
    encoded = bytearray([code.pop(0)])
    
    for i in range(0, len(code)):
        encoded.append(code[i] ^ encoded[i])

    return encoded

def decode(code: bytearray) -> bytearray:
    code.reverse()
    decoded = bytearray()

    for i in range(0, len(code)-1):
        decoded.append(code[i] ^ code[i+1])
    decoded.append(code[len(code)-1])

    decoded.reverse()
    return decoded


code = b'<SHELLCODE_TO_REPLACE>'

if len(sys.argv) > 1:
    if sys.argv[1] == "0":
        result = encode(bytearray(code))
    elif sys.argv[1] == "1":
        result = decode(bytearray(code))

print("\\x"+"\\x".join(str(binascii.hexlify(result, '-')).replace("b","").replace("'", "").split('-')))
