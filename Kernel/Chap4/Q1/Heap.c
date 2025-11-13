#include <stdio.h>
#include <stdlib.h>


int main()
{
	char *str = malloc(sizeof(char) * 1024);

	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';

	printf("Using Heap\n");
	printf("Address: %p\n", str);
	printf("%s\n", str);

	free(str);

	return 0;
}
