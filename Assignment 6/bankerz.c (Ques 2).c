#include<stdio.h>
#include<stdlib.h>


int P,R;
int processes[20];
int avail[20];
int allot[20][20];
int max[20][20];
int need[20][20];


void initialize()
{

	printf("enter the number of processes: ");
	scanf("%d",&P);
	printf("enter the number of resource types: ");
	scanf("%d",&R);

	 
	int i,j;
	for(i=0;i<P;i++)
		processes[i]=i;

	printf("enter the AVAILABLE matrix[resource]: ");
	for(i=0;i<R;i++)
		scanf("%d",&avail[i]);
	    
	printf("enter the ALLOTMENT matrix[process][resource]: ");
	for(i=0;i<P;i++)
		for(j=0;j<R;j++)
			scanf("%d",&allot[i][j]);
	
	printf("enter the MAX matrix[process][resource]: ");
	for(i=0;i<P;i++)
		for(j=0;j<R;j++)
			scanf("%d",&max[i][j]);

	return;
}


int isSafe() 
{ 
	int finish[P];
	for (int i = 0; i < P ; i++) 
        finish[i] = 0; 
 

	int safeSeq[P]; 
  
	int work[R]; 
	for (int i = 0; i < R ; i++) 
        work[i] = avail[i]; 

	int count = 0; 
	while (count < P) 
	{ 
        int found = 0; 
        for (int p = 0; p < P; p++) 
        { 
            if (finish[p] == 0) 
            { 
                int j; 
                for (j = 0; j < R; j++) 
                    if (need[p][j] > work[j]) 
                        break; 

                if (j == R) 
                { 
                    for (int k = 0 ; k < R ; k++) 
                        work[k] += allot[p][k];  
                    
                    safeSeq[count++] = p; 

		    int k;
		    printf("available matrix after process (%d) finishes its execution is : ",p);
		    for(k=0;k<R;k++)
		    	printf("%d ",work[k]);
		    printf("\n");
                    finish[p] = 1; 
  
                    found = 1; 
                } 
            } 
        } 
  
        if (found == 0) 
        { 
            printf("\nSystem is not in safe state\n"); 
            return 0; 
        } 
    } 

    printf("\nSystem is in safe state\nthe safe sequence is: "); 
    for (int i = 0; i < P ; i++) 
        printf("%d, ",safeSeq[i]); 
  
    return 1; 
} 
  
int main() 
{ 

	initialize();
	int answer,i,j;
	for(i=0;i<P;i++)
		for(j=0;j<R;j++)
			need[i][j]=max[i][j]-allot[i][j];		


	printf("\n");
	printf("current allocation matrix is: ");
	for(i=0;i<R;i++)
		printf("%d ",avail[i]);
	printf("\n");
	answer=isSafe(); 

	return 0; 
} 

