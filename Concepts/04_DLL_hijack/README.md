# DLL hijack

This is an example of how to execute a DLL hijack in Windows. /Demo contains a video recording demonstrating the concept.

When looking for a DLL inside the system, Windows will sometimes try different paths before finding the right one. Using an application monitoring the processess on the system (like Process Monitor from the Windows Sysinternals Suite) we can observe all the attempts from the system at find the required DLL to a program and try to find an unsuccessfull attempt at loading this DLL from a specific path. Once we found this, we can then place our own malicious DLL at this path, and restart the program that should now load our malicious DLL.

![Watch a demo here]()