# Process injection

This is an example of how to execute a process injection in Windows. All the code used is in /Source_code, /Demo contains a recording of the code in execution.

The program will ask the Windows API to allocate some memory for a new process, copy the given shellcode into this memory, and execute it.

Obviously this won't bypass any antivirus on its own and Windows Defender is disabled for the demonstration, but it can be usefull once combined with other methods.

![Watch a demo here](https://raw.githubusercontent.com/geoffrey-diederichs/Red_team_tools/main/Concepts/01_Process_injection/Demo/process_inj_demo.mp4)

## How to use

Replace <SHELLCODE_TO_REPLACE> within the process_injec.c at line 5 with the shellcode you want to execute. Then just compile and execute.
