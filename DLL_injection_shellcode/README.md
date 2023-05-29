# DLL injection

This is an example of how to use a DLL injection to inject shellcode in Windows. All the code used is in /Source_code, /Demo contains a recording of the code in execution.

The launcher will look for an ongoing instance of notepad.exe. If found, it will load the dll library (using the path given in the launcher's code) and attach it to the ongoing notepad. Doing so will execute the DDL_PROCESS_ATTACH section which runs the dll_injec function. This function will decode the shellcode using the given key, and then execute it using a process injection method.

![Watch a demo here](https://raw.githubusercontent.com/geoffrey-diederichs/Red_team_tools/main/DLL_injection_shellcode/Demo/dll_injection_shellcode_demo.mp4)

## How to use

Replace <PATH_TO_REPLACE> with the full path to where the dll will be stored in launcher.c at line 23. Use \\\\ instead of \\. For example :

```C
char DLL[] = "C:\\Users\\example\\dll.dll";
```

Encode the shellcode you want to use with a XOR cipher. Please refer to
[XOR cipher](https://github.com/geoffrey-diederichs/Red_team_tools/tree/main/Ciphers/XOR_cipher) for more details. Afterwards, replace <CODE_TO_REPLACE> and <KEY_TO_REPLACE> with the encoded payload and the key used to encode it in dll.dll at lines 5 and 7. For example :

```C
unsigned char code[] = "\x12\x34\x56";
int code_size = sizeof(code);
char key[] = "this_is_the_key";
```

Once compiled, make sure the dll is at the correct path (the launcher can be executed from anywhere), spawn a notepad and execute the launcher.
