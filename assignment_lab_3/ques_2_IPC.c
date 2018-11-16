#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd[2];
    char buffer[500];

    pipe(fd);

    if (fork() != 0)
    {
        close(fd[0]);

	FILE *fptr;
	if((fptr = fopen(argv[1],"r")) == NULL)
	{
		printf("Error getting file");
		exit(1);
	}
	fscanf(fptr,"%[^\n]",buffer);
	fclose(fptr);

        write(fd[1], buffer, strlen(buffer)+1);
        printf("Parent(%d) sends from %s : %s\n", getpid(), argv[1], buffer);
	printf("%d\n",fd[1]);

        close(fd[1]);
    }
    else
    {   
        close(fd[1]);
        
	char file_data[500];
        read(fd[0], file_data, 500);
	printf("Child(%d) received value: %s\n", getpid(), file_data);
	printf("child writing to location : %s\n" , argv[2]);
	FILE *fptr;
        
	if((fptr = fopen(argv[2],"w")) == NULL)
	{
		printf("Error getting file");
		exit(1);
	}
	fprintf(fptr,"%s",file_data);
	fclose(fptr);
        close(fd[0]);
    }
    return 0;
}
