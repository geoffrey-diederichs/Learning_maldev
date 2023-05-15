#include <stdio.h>
#include <string.h>

unsigned char code[] =  "\xdb\x1b\xa5\x12\x6c\x7f\xe1\x38\x4c\x68\x9c\xc4\xf5\x2e";

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
	char encoded[sizeof(code)];	
	
	encoded[0] = code[0];
	int i;
	for (i = 1; i < sizeof(code)-2; i++)
		encoded[i] = code[i] ^ encoded[i-1];
	encoded[i] = code[0] ^ encoded[i-1];
	encoded[++i] = '\0';

	printf("%d\n", sizeof(encoded));
	for (i = 0; i < sizeof(encoded); i++)
		printf("\\x%hhx", encoded[i]);
	printf("\n");

	return 0;	
}

int decode()
{
	strrev(code);
	unsigned char decoded[sizeof(code)];
	decoded[0] = '\0';

	int i;
	for (i = 1; i < sizeof(code)-1; i++)
		decoded[i] = code[i] ^ code[i+1];
	decoded[i] = code [i];
	strrev(decoded);
	printf("%d\n", sizeof(decoded));                 	
	for (i = 0; i < sizeof(decoded); i++)
		printf("\\x%hhx", decoded[i]);
	printf("\n");                         
	
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc > 1) {
		if (strcmp(argv[1], "0") == 0)
			encode();
		else if (strcmp(argv[1], "1") == 0)
			decode();
	}

	return 0;
}
