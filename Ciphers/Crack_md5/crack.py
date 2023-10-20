import hashlib

def md5Hash(x: str):
    result = hashlib.md5(x.encode())
    return result.hexdigest()


hash = "<HASH>"

f = open('<WORDLIST>', 'r', encoding='<WORDLIST_ENCODING>')
file = f.read()

start = 0
for i in range(0, len(file)):
    if file[i] == '\n':
        current = file[start:i]
        if md5Hash(current) == hash:
            print(current)
            exit()
        start = i+1
