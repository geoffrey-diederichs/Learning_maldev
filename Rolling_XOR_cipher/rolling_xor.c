#include <stdio.h>
#include <string.h>

int strrev(char *str);
int encode();
int decode();
int print_bytes(char *str);

unsigned char code[] =  "<SHELLCODE_TO_REPLACE>";
int code_size = sizeof(code);

int main(int argc, char* argv[])
{
	if (argc > 0) {
		if (strcmp(argv[1], "0") == 0)
			encode();
		else if (strcmp(argv[1], "1") == 0)
			decode();
	}
	
	return 1;
}

int strrev(char *str)
{
	int len = strlen(str);
	
	int i, temp;
	for (i = 0; i < len/2; i++) {
		temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
	
	return 0;
}

int encode()
{
	char encoded[code_size];	
	
	encoded[0] = code[0];
	int i;
	for (i = 1; i < code_size-1; i++)
		encoded[i] = code[i] ^ encoded[i-1];
	encoded[i] = '\0';

	print_bytes(encoded);

	return 0;	
}

int decode()
{
	strrev(code);
	unsigned char decoded[code_size];

	int i, len = strlen(code);
	for (i = 0; i < len-1; i++) 
		decoded[i] = code[i] ^ code[i+1];
	decoded[i] = code[i];
	decoded[++i] = '\0';
	strrev(decoded);

	print_bytes(decoded);
	
	return 0;
}

int print_bytes(char *str)
{
	int len = strlen(str);
	printf("%d bytes\n", len);                 		
	
	int i;
	for (i = 0; i < len; i++)
		printf("\\x%hhx", str[i]);
	printf("\n");                         

	return 0;
}
