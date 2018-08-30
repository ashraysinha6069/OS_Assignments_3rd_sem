#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void print_usage(char *this){
    fprintf(stderr, "SYNTAX ERROR:\nUsage: %s [old filename] [new filename]\n", this);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
	errno = 0;
    FILE *fpr, *fpw;
	char ch;


		print_usage(argv[0]);
    return 0;
}
