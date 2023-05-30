# DLL injection

This is an example of how to execute a DLL injection in Windows. All the code used is in /Source_code, /Demo contains a recording of the code in execution.

The launcher will look for an ongoing instance of notepad.exe. If found, it will load the dll library (using the path given in the launcher's code) and attach it to the ongoing notepad. Doing so will execute the DDL_PROCESS_ATTACH section of the dll which opens a message box.

![Watch a demo here](https://raw.githubusercontent.com/geoffrey-diederichs/Red_team_tools/main/Concepts/02_DLL_injection/Demo/dll_injection_demo.mp4)

## How to use

Replace <PATH_TO_REPLACE> with the full path to where the dll will be stored in launcher.c at line 23. Use \\\\ instead of \\. For example :

```C
char DLL[] = "C:\\Users\\example\\dll.dll";
```

To compile the dll with gcc, use the -shared flag. For example under linux :

```
$ x86_64-w64-mingw32-gcc dll.c -o dll.dll -shared
$ x86_64-w64-mingw32-gcc launcher.c -o launcher.exe 
```

Then, make sure the dll is at the correct path (the launcher can be executed from anywhere), spawn a notepad and execute the launcher.
