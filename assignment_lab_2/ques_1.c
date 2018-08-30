#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c[1000];
	FILE *fptr;

	if ((fptr = fopen("config.txt", "r")) == NULL)
	{
		printf("error opening file");	
	}
	else
	{
		fscanf(fptr , "%[^\n]", c);

		printf("data from file\n%s", c);
		fclose(fptr);
	}
	return 0;
}
