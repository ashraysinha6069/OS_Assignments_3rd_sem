#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int n,m,k;
int* S;
int* C;
int top=-1;
int c=0;
int mutex=1,full=0,empty,x=0;


void input(){
    printf("Give value of n:");
    scanf("%d",&n);
    printf("Give value of m:");
    scanf("%d",&m);
    printf("Give value of k:");
    scanf("%d",&k);
    S=(int *)malloc(sizeof(int)*k);
    C=(int *)malloc(sizeof(int)*(n*m));
    empty=k;
}

int wait(int s)
{
    while(s<0);
    return (--s);
}
 
int sig(int s)
{
    return(++s);
}

void Put(int item)
{

  	int value;
  	if(top==-1)
    	{
      		sleep(1);
    	}
	top++;
	S[top]=item;
	printf("  %d",item);

}

void * Producer()
{
	empty=wait(empty);
	mutex=wait(mutex);        
        int i;
	srand(clock());
	if(k<m){
		for(i = 0; i < k; i++)
		{
			int temp;	
			temp=rand()%100;
			Put(temp);
    		}
	}
	else{
		for(i = 0; i < m; i++)
		{
		int temp;
	        temp=rand()%100;
		Put(temp);
	        }
	}	
	mutex=sig(mutex);
	full=sig(full);
}

void Get()
{
	int item;
	if(top==-1)
    	{
      		sleep(1);
    	}
	item=S[top];
	top--;
	C[c++]=item;
}

void * Consumer()
{
	full=wait(full);
	mutex=wait(mutex);
	int i;
	if(k<m){
		for(i = 0; i < k; i++)
    		{
	      		Get();
    		}
	}
	else{
		for(i = 0; i < m; i++)
		{
		      Get();
		}
	}
	mutex=sig(mutex);
	empty=sig(empty);
}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;


    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;


        swap(&arr[min_idx], &arr[i]);
    }
}
int main()
{
  
	int i;
  	input();
  	pthread_t ptid[n],ctid[n];
	printf("Printing the items produced by producer processes...\n");
  	for(i=0;i<n;i++){
	  	pthread_create(&ptid[i], NULL,Producer, NULL);
      		sleep(1);
	  	pthread_create(&ctid[i], NULL,Consumer, NULL);  
  	}
	for(i=0;i<n;i++){
    		pthread_join(ptid[i], NULL);
	  	pthread_join(ctid[i], NULL);
	}
	selectionSort(C,c);
	printf("\n");
	printf("Printing the items received by parent process (in ascending order)\n");
	for(i=0;i<c;i++)
		printf("  %d",C[i]);
	printf("\nFinal value of stack top pointer= %d\n",top);
	return 0;
}
