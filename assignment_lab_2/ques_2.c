#include <unistd.h>		
#include <stdio.h>		
#include <fcntl.h>		

int main(int argc, char *av[])
{
  if (argc<2) 
	return 0;
  int fd = open(av[1],O_RDONLY);
  int size = lseek(fd, 0, SEEK_END);
  printf("Size of the file = %d KB\n", size);
  close(fd);
  
  return 0;
}

