#include <stdio.h>
#include <dirent.h>

int main()
{
	DIR *d;
	struct dirent *ent;
	char str[1000];
	scanf("%s", str);
	if ((d =opendir(str))!=NULL)
	{
		while((ent = readdir(d)) != NULL)
		{
			printf("%s\n" ,ent->d_name);
		}
		closedir(d);
	}
	else
	{
		printf("error");
		return 0;
	}
}
