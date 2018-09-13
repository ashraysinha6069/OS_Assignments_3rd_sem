#include <stdio.h>
#include <pthread.h>

int A[100][100],B[100][100],C[100][100];
int ctr=0;
int m,n,o;
void *multiply(void *arg)
{	
	for(int i=ctr;i<ctr+1;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
	ctr++;
} 

int main()
{	
	printf("Enter m");
	scanf("%d" , &m);
	printf("Enter o");
	scanf("%d" , &o);
	printf("Enter n");
	scanf("%d" , &n);
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<o;j++)
		{
			A[i][j]=rand()%10;		
		}
	}
	for (int i=0;i<o;i++)
	{
		for (int j=0;j<n;j++)
		{
			B[i][j]=rand()%10;		
		}
	}
	printf("Matrix A :\n\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<o;j++)
		{
			printf("%d ",A[i][j]);		
		}printf("\n");
	}
	printf("\nMATRIX B: \n\n");
	for (int i=0;i<o;i++)
	{
		for (int j=0;j<n;j++)
		{
			printf("%d ",B[i][j]);		
		}printf("\n");
	}

	pthread_t th[m];

	for (int i=0;i<m;i++)
	{
		int *p;
		pthread_create(&th[i],NULL,multiply,(void*)(p));
	}
	for(int i=0;i<m;i++)
	{
		pthread_join(th[i],NULL);
	}
	printf("\nMATRIX C: \n\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			printf("%d ",C[i][j]);		
		}printf("\n");
	}
	return 0;
}
