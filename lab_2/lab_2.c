#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main()
{
	key_t key = ftok("file1",65);	
	int id = shmget(key,1024,0666|IPC_CREAT);
	char *str = (char *) shmat(id,(void*)0,0);

	printf("writing in file\n");
	gets(str);
	printf("wrote some data\n");
	shmdt(str);
	
	return 0;
}
