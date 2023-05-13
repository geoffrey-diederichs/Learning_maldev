# Basic DLL injection

The launcher will look for an ongoing instance of notepad.exe. If found, it will load the dll library (using the path given in the launcher's code) and attach it to the ongoing notepad. Doing so will execute the DDL_PROCESS_ATTACH section of the dll which opens a message box.

All the code used is in /source_code, /compiled contains a compiled version of it, /demos contains a recording of the code in execution.

## How to use

When using the compiled version the dll needs to be stored at :

C:\dll.dll

You can change that by modifiyng the dll's path at line 23 of launcher.cpp.
You can then compile those files under linux using mingw-w64. For example with debian :

```sh
$ sudo apt update && sudo apt upgrade
$ sudo apt install mingw-w64
$ x83_64-w64-mingw32-gcc dll.cpp -o dll.dll -shared
$ x83_64-w64-mingw32-gcc launcher.cpp -o launcher.exe -fpermissive
```

Make sure the dll is at the correct path (the launcher can be executed from anywhere) and just execute the launcher.

[![Demo](https://github.com/geoffrey-diederichs/Red_team_tools/blob/main/Basic_DLL_injection/Demo/windows.jpg)](https://github.com/geoffrey-diederichs/Red_team_tools/blob/main/Basic_DLL_injection/Demo/test.mp4)
