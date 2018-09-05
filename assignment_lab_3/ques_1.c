#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int A[4][4],B[4][4],C[4][4];
int ctr=0;

void *multiply(void *arg)
{	
	for(int i=ctr;i<ctr+1;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
	ctr++;
} 

int main()
{
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			A[i][j]=rand()%10;
			B[i][j]=rand()%10;		
		}
	}
	printf("Matrix A :\n\n");
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			printf("%d ",A[i][j]);		
		}printf("\n");
	}
	printf("\nMATRIX B: \n\n");
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			printf("%d ",B[i][j]);		
		}printf("\n");
	}

	pthread_t th[4];

	for (int i=0;i<4;i++)
	{
		int *p;
		pthread_create(&th[i],NULL,multiply,(void*)(p));
	}
	for(int i=0;i<4;i++)
	{
		pthread_join(th[i],NULL);
	}
	printf("\nMATRIX C: \n\n");
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			printf("%d ",C[i][j]);		
		}printf("\n");
	}
	return 0;
}
