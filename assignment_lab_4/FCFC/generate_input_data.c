#include<stdio.h>
#include<stdlib.h> 
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
	printf("\n\tEnter no. of sets of processes. (~50)\n\t");
	int s,i,j;
	scanf("%d",&s);
	FILE *f=fopen("inputdata.txt","w+");
	fprintf(f,"%d\n",s);
	for(i=0;i<s;i++)
	{
		int n=rand()%30+2;
		fprintf(f,"%d ",n);
		int arr[n];
		for(j=0;j<n;j++)
		{
			arr[j]=rand()%50;
		}
		selectionSort(arr,n);		//RANDOMLY  generated n size array but in ascending order.
		for(j=0;j<n;j++)
			fprintf(f,"%d %d ",arr[j],rand()%90+1);		//arrival time and burst time
		fprintf(f,"\n");
	}
	return 0;
}		