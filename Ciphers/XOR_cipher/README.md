# XOR cipher

Takes a message and encodes or decodes it using a XOR cipher. Coded in both C and python.

# How to use

First modify <MESSAGE_TO_REPLACE> inside the code (the programs can also take shellcodes as inputs as shown below), and enter a key by modifying <KEY_TO_REPLACE>. Then run the program. Since this is a symmetric-key algorithm, running this program once more using the output (with the same key) will give you the initial message.

These programs will give you 3 outputs : 
- the number of bytes in the result
- the result in bytes 
- the result in utf-8 or ascii encoding (which will frequently be nonsense)

# Example

We're going to use the python program to encode the message <MESSAGE_TO_REPLACE> using the key <KEY_TO_REPLACE>. Then we'll take the output and decode it using the C program :

```sh
$ cat xor.py | grep "message = b'"
message = b'<MESSAGE_TO_REPLACE>'
$ cat xor.py | grep "key ="
key = b'<KEY_TO_REPLACE>'
$ python3 xor.py
20 bytes
\x00\x06\x00\x0a\x0c\x15\x08\x1a\x0d\x11\x1f\x13\x13\x06\x15\x72\x7d\x08\x00\x67


rg
$ cat xor.c | grep "char message"
unsigned char message[] =  "\x00\x06\x00\x0a\x0c\x15\x08\x1a\x0d\x11\x1f\x13\x13\x06\x15\x72\x7d\x08\x00\x67";
$ cat xor.c | grep "char key" 
char key[] = "<KEY_TO_REPLACE>";
$ gcc xor.c -o xor ; ./xor 
\x3c\x4d\x45\x53\x53\x41\x47\x45\x5f\x54\x4f\x5f\x52\x45\x50\x4c\x41\x43\x45\x3e
<MESSAGE_TO_REPLACE>
```
