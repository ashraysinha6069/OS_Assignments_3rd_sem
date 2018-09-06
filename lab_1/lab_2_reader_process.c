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

	printf("reading from memory\n");
	printf("%s",str);
	shmdt(str);
	shmctl(id,IPC_RMID,NULL);
	
	return 0;
}
