
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    FILE *fp_read, *fp_write;
    int counter = 1, i = 0;
    char ch;

    fp_read = fopen(argv[1], "r");
    fp_write = fopen(argv[1], "r+");

    if(!fp_read || !fp_write)
    {
        printf("File not present\n");
        exit(1);
    }

    fseek(fp_read, 0, SEEK_END);
    int size = ftell(fp_read);
    fseek(fp_read, 0, SEEK_SET);

    while(counter < size)
    {
        ch = fgetc(fp_read);
        if(counter % 5 != 0)
        {
            fputc(ch, fp_write);
        }
        else
            i++;
        counter++;
    }

    fclose(fp_read);
    fclose(fp_write);
    truncate(argv[1],size-i-1);
    return 0;
}
