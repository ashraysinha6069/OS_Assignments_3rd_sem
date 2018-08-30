#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{

	printf("enter file location\n");
	char buffer[10000], loc[100];
	
	scanf("%s", loc);
	printf("Enter data\n");
	scanf("%s" ,buffer);
	
	FILE *fptr;
	fptr = fopen(loc,"w");
	if(fptr == NULL){
		printf("Error");
		exit(1);}

	fprintf(fptr,"%s",buffer);
	fclose(fptr);
	return 0;
}



