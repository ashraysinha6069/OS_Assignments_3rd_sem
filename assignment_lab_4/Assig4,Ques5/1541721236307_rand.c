#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE* fp ;
	fp = fopen("input3.txt","w");
	int x=60,i ;
	
	for(i=0;i<x;i++){
		int n = rand()%10+1;
		printf("%d\n",n);
		fprintf(fp,"%d\n",n);
		int j;
		for(j=0;j<n;j++){

			
				int l,m,f;
				l = rand();
				fprintf(fp,"%d\t",l%20);	
				m = rand();
				fprintf(fp,"%d\t",m%30);
				f = rand();
				fprintf(fp,"%d\n",f%13+1);



		}

	}

return 0;
}
