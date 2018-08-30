#include<stdio.h>
#include<fcntl.h>
int main(){

char buff[1000000],fn[10];
int fd,n;

printf("Enter the filename\n");

scanf("%s",fn);

fd = open(fn,O_RDONLY);
n = read(fd,buff,1000000);

n = write(1,buff,n);

close(fd);

}
