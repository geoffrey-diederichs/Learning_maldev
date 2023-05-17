# Rolling XOR cipher

Takes a message and encodes or decodes it using a rolling XOR cipher.

# How to use

First modify <MESSAGE_TO_REPLACE> inside the code (the programs can also take shellcodes as inputs as shown below). Then to encode it, run the program with 0 as argument. To decode it, run the program with 1 as argument.

The programs will give you 3 outputs : the number of bytes in the result, the result in bytes and the result in utf-8 or ascii encoding (which will frequently be nonsense).

# Example

```sh
$ message='testing_this'
$ sed -i "s/<MESSAGE_TO_REPLACE>/${message}/" rolling_xor.py
$ python3 rolling_xor.py 0
12 bytes
\x74\x11\x62\x16\x7f\x11\x76\x29\x5d\x35\x5c\x2f
tbv)]5\/
$ sed -i "s/${message}/<MESSAGE_TO_REPLACE>/" rolling_xor.py
$ message='\x74\x11\x62\x16\x7f\x11\x76\x29\x5d\x35\x5c\x2f'
$ sed -i "s/<MESSAGE_TO_REPLACE>/${message}/" rolling_xor.py
$ python3 rolling_xor.py 1
12 bytes
\x74\x65\x73\x74\x69\x6e\x67\x5f\x74\x68\x69\x73
testing_this
```
