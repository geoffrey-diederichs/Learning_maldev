# Crack md5

Tries every entry in a given dictionnary to find out if it's the one used to produce a given md5 hash.

## How to use

Replace <HASH> on line 8 with the hash to crack, <WORDLIST> on line 10 with the path to the dictionnary to use, and <WORDLIST_ENCODING> on line 10 with the encoding used in the dictionnary.

## Example

```sh
$ python3 -c 'import hashlib; print(hashlib.md5("test".encode()).hexdigest())'
098f6bcd4621d373cade4e832627b4f6
$ cat crack.py | grep 'hash ='         
hash = "098f6bcd4621d373cade4e832627b4f6"
$ cat dictionnary.txt       
hello
test
world
$ cat crack.py | grep 'open(' 
f = open('dictionnary.txt', 'r', encoding='utf-8')
$ python3 crack.py
test
```
