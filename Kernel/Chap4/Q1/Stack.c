#include <stdio.h>
#include <stdlib.h>


int main()
{
	char str[6];

	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';

	printf("Using Stack\n");
	printf("Address: %p\n", str);
	printf("%s\n", str);

	return 0;
}
