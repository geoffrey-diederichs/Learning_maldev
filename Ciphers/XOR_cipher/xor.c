#include <stdio.h>

unsigned char message[] =  "<MESSAGE_TO_REPLACE>";
int message_size = sizeof(message);
char key[] = "<KEY_TO_REPLACE>";
int key_size = sizeof(key);

int print_result(char *str, int len)
{
	printf("%d bytes\n", len);                 		
	
	int i;
	for (i = 0; i < len; i++)
		printf("\\x%hhx", str[i]);
	printf("\n");                         
	
	for (i = 0; i < len; i++)
		printf("%c", str[i]);
	printf("\n");	

	return 0;
}

int main(int argc, char* argv[])
{
	int i;
	for (i = 0; i < message_size-1; i++)
		message[i] = message[i] ^ key[i%(key_size-1)];
	message[i] = '\0';

	print_result(message, message_size-1);

	return 0;
}
