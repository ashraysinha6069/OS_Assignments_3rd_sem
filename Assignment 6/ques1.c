#include<stdio.h>
int main()
{
	int m,n;
	printf("Enter no. of processes\n");
	scanf("%d",&n);
	printf("Enter no. of resource types\n");
	scanf("%d",&m);
	
	int available[m],allocation[n][m],request[n][m],i,j,safesequence[n],top=0;		//max[n][m] 
	
	printf("Define initial state:\n\n");
	for(i=0;i<m;i++)
	{
		printf("Enter no. of instances currently free, of Resource #%d \n",i);
		scanf("%d",&available[i]);
	}
	
	printf("Define initial allocation state:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("Enter no. of instances of Resource #%d held by process %d  \n",j,i);
			scanf("%d",&allocation[i][j]);
		}
	}
	
	printf("Define initial request state:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("Enter no. of instances of Resource #%d being requested by process %d  \n",j,i);
			scanf("%d",&request[i][j]);
		}
	}
	/*
	printf("Allocationtable:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",allocation[i][j]);
		}
		printf("\n");
	}
	
	printf("Request table:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",request[i][j]);
		}
		printf("\n");
	}

	printf("available table:\n");
	
	for(i=0;i<m;i++)
		printf("%d  ",available[i]);

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			max[i][j]=allocation[i][j]+request[i][j];
	*/
	//		************************************************************
	//		Deadlock Detection Algorithm
	int work[m],finish[n];
	for(i=0;i<n;i++)
		finish[i]=0;			// step 1
	for(i=0;i<m;i++)
		work[i]=available[i];	// step 1
	int k;
	for(i=0;i<n;i++){			// step 1
		k=0;
		for(j=0;j<m;j++){
			if(allocation[i][j]==0)
				k++;
		}
		if(k==m)
			finish[i]=1;
	}

	int f,d=0;


	while(1){
		for(i=0;i<n;i++){
			f=0;
			if(finish[i]==0){
				for(j=0;j<m;j++)
					if(request[i][j]<=work[j])
						f++;
			}
			if(f==m)			//escape to step 3 if such 'i' is found.
				break;	
		}
		if(f==m)				// step 3
		{
			for(j=0;j<m;j++)
				work[j]+=allocation[i][j];
			finish[i]=1;
			safesequence[top]=i;
			top++;
			continue;
		}
		break;
	}
	for(j=0;j<n;j++)			//step 4.
		if(finish[j]==0){
			printf("Deadlock!\n");
			return 0;
	}
	else
		printf("\n\n\nNo Deadlock\n");
	
	//		************************************************************
	//		Printing Of Safe Sequence
	
	printf("\n\nA Possible SafeSequence is:\t");
	for(i=0;i<n;i++)
		printf("P%d..->",safesequence[i]);
	
	//		************************************************************
	//		Printing Of Available Array after every process.
	printf("\n\nIntially:\n");
	printf("Available table:\t\t");
	for(i=0;i<m;i++)
		printf("%d  ",available[i]);
	printf("\n\n\n");
	for(i=0;i<n;i++)
	{
		k = safesequence[i];
		printf("\nAfter Process P%d\t\t",k);

		for(j=0;j<m;j++)
			available[j]+=allocation[k][j];
		for(j=0;j<m;j++)
			printf("%d  ",available[j]);
	}
}