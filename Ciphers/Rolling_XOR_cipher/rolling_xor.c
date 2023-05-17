#include <stdio.h>
#include <string.h>

int encode();
int decode();
int strrev(char *str, int len);
int print_result(char *str, int len);

unsigned char message[] =  "<MESSAGE_TO_REPLACE>";
int message_size = sizeof(message);

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



int encode()
{
	unsigned char encoded[message_size];	
	
	encoded[0] = message[0];
	int i;
	for (i = 1; i < message_size-1; i++)
		encoded[i] = message[i] ^ encoded[i-1];
	encoded[i] = '\0';

	print_result(encoded, message_size-1);

	return 0;	
}

int decode()
{
	strrev(message, message_size-1);
	unsigned char decoded[message_size];

	int i;
	for (i = 0; i < message_size-2; i++) 
		decoded[i] = message[i] ^ message[i+1];
	decoded[i] = message[i];
	decoded[++i] = '\0';
	strrev(decoded, message_size-1);

	print_result(decoded, message_size-1);
	
	return 0;
}

int strrev(char *str, int len)
{
	int i, temp;
	for (i = 0; i < len/2; i++) {
		temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
	
	return 0;
}

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
