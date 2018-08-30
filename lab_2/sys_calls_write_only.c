#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{

	printf("enter file location\n");
	char *buffer, loc[100];
	
	scanf("%s", loc);
	printf("Enter data\n");
	scanf("%s" ,buffer);
	fgets(buffer,100,stdin);
	int file_id = open(loc,O_CREAT|O_WRONLY);
	int n = write(file_id, buffer, 10000);
	n = write(file_id,buffer,strlen(buffer));
	close(file_id);
	return 0;
}



