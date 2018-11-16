#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void show_frame(int frame[],int n)
{
	printf("\nFrame status is:");
	for(int k=0;k<n;k++)
	{
		if(frame[k]!=-1)
			printf("%d   ",frame[k]);
	}
}
int main()
{
	int page_time[1000]={0};
	FILE *fp;
	fp=fopen("pf.txt","w+");
	int s;
	printf("Enter no. pages: ");
	scanf("%d",&s);
	int page_num[s];//={2,3,5,2,1,7,8,9,0,1,9,1};
	srand(time(0));
	for(int i=0;i<s;i++)
		page_num[i]=rand()%50;
	for(int c1=0;c1<10;c1++)
	{
		int n, p_fault=0;
		printf("\nEnter no. of frames:");
		scanf("%d",&n);
		int frame[n];;
		for(int i=0;i<n;i++)
		{
			frame[i]=-1;
			//printf("  %d",frame[i]);
		}
		printf("\n");
		clock_t start,end;
		long int max,span=0;
		int page_replace,frame_index,flag,flag1;
		for(int z=0;z<s;z++)
		{
			flag=0;
			flag1=0;
			max=-1;
			for(int k=0;k<n;k++)
			{
				if(frame[k]==-1)
				{
					frame[k]=page_num[z];
					p_fault++;
					page_time[page_num[z]]=clock();
					//printf("\n %d",page_time[page_num[z]]);
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				show_frame(frame,n);
			}
			else
			{
				for(int i=0;i<n;i++)
				{
					if(frame[i]==page_num[z])
					{
						page_time[page_num[z]]=clock();
						//printf("\n %d",page_time[page_num[z]]);
						flag1=1;
					}
				}
				if(flag1==1)
				{
					show_frame(frame,n);
				}
				else
				{
					for(int i=0;i<n;i++)
					{
						end=clock();
						span=end-page_time[frame[i]];
						if(max<span)
						{
							max=span;
							page_replace=frame[i];
							frame_index=i;
						}
					}
					frame[frame_index]=page_num[z];
					p_fault++;
					page_time[page_num[z]]=clock();
					//printf("\n %d",page_time[page_num[z]]);
					show_frame(frame,n);
				}
			}
		}
		printf("\nNo. of page faults are: %d\n",p_fault );
		fprintf(fp,"%d		%d\n",n,p_fault);
	}
	return 0;
}