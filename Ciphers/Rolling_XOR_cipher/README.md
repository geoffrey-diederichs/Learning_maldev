# Rolling XOR cipher

Takes a message and encodes or decodes it using a rolling XOR cipher. Coded in both C and python.

# How to use

First modify <MESSAGE_TO_REPLACE> inside the code (the programs can also take shellcodes as inputs as shown below). Then to encode it, run the program with 0 as argument. To decode it, run the program with 1 as argument.

These programs will give you 3 outputs : 
- the number of bytes in the result 
- the result in bytes 
- the result in utf-8 or ascii encoding (which will frequently be nonsense)

# Example

We're going to use the python program to encode the message <MESSAGE_TO_REPLACE>. Then we'll take the output and decode it using the C program :

```sh
$ cat rolling_xor.py | grep "message ="
message = b'<MESSAGE_TO_REPLACE>'
$ python3 rolling_xor.py 0
20 bytes
\x3c\x71\x34\x67\x34\x75\x32\x77\x28\x7c\x33\x6c\x3e\x7b\x2b\x67\x26\x65\x20\x1e
<q4g4u2w(|3l>{+g&e 
$ cat rolling_xor.c | grep "char message"
unsigned char message[] = "\x3c\x71\x34\x67\x34\x75\x32\x77\x28\x7c\x33\x6c\x3e\x7b\x2b\x67\x26\x65\x20\x1e";
$ gcc rolling_xor.c -o rolling_xor ; ./rolling_xor 1
20 bytes
\x3c\x4d\x45\x53\x53\x41\x47\x45\x5f\x54\x4f\x5f\x52\x45\x50\x4c\x41\x43\x45\x3e
<MESSAGE_TO_REPLACE>
```
