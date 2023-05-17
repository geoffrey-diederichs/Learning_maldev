# Rolling XOR cipher

Takes a shellcode and encodes or decodes it using a rolling XOR cipher.
First modify <SHELLCODE_TO_REPLACE> inside the code. Then to encode it, run the program with 0 as argument. To decode it, run the program with 1 as argument.
For example :

```sh
$ shellcode='\\x12\\x34\\x56'
$ sed -i "s/<SHELLCODE_TO_REPLACE>/${shellcode}/" rolling_xor.py
$ python3 rolling_xor.py 0
\x12\x26\x70
$ sed -i "s/${shellcode}/<SHELLCODE_TO_REPLACE>/" rolling_xor.py
$ shellcode='\\x12\\x26\\x70'
$ sed -i "s/<SHELLCODE_TO_REPLACE>/${shellcode}/" rolling_xor.py
$ python3 rolling_xor.py 1
\x12\x34\x56
```

The C code curently has issues with null characters because of strlen, will fix that.
