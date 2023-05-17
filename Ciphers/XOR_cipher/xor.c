#include <stdio.h>

unsigned char message[] =  "<MESSAGE_TO_REPLACE>";
int message_size = sizeof(message);
char key[] = "<KEY_TO_REPLACE>";

int print_bytes(char *str, int len)
{
	printf("%d bytes\n", len);                 		
	
	int i;
	for (i = 0; i < len; i++)
		printf("\\x%hhx", str[i]);
	printf("\n");                         

	return 0;
}

int main(int argc, char* argv[])
{
	unsigned char encoded[message_size];	
	
	int i;
	for (i = 0; i < message_size-1; i++)
		encoded[i] = message[i] ^ key[0];
	encoded[i] = '\0';

	print_bytes(encoded, message_size-1);

	return 0;
}
