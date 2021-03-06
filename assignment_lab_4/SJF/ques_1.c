#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>

struct node
{
	char name[5];
	int arrival;
	int burst;	
	struct node* next;	
};

struct node* append(struct node* head,char arr[],int arri,int bur)
{
		struct node* tempn = (struct node*)malloc(sizeof(struct node*));
		struct node* temp_p = NULL;
		temp_p=head;
		strcpy(tempn->name,arr);
		tempn->arrival = arri;
		tempn->burst = bur;
		tempn->next = NULL;
		if (head==NULL)
			return tempn;
		else
		{			 
			while(head->next!=NULL)
			{
				head=head->next;
			}
		}
		head->next=tempn;
		return temp_p;
}

int print(struct node* head)
{
	while(head!=NULL)
	{
		printf("%s   %d  %d\n" ,head->name,head->arrival,head->burst);
		head = head->next;

	}
	return 0;
}

/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b) 
{ 
        int temp = a->arrival; 
        a->arrival = b->arrival; 
        b->arrival = temp;
	temp = a->burst;
 	a->burst = b->burst;
	b->burst = temp;
	char temp_arr[10];
	strcpy(temp_arr,a->name);
	strcpy(a->name,b->name);
	strcpy(b->name,temp_arr);
}

/* Bubble sort the given linked list */
void bubbleSort(struct node *start) 
{ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->arrival > ptr1->next->arrival) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}  

double variance(int arr[],int n)
{
	    int average,sum=0,sum1=0,variance;	    
	    for (int i = 0; i < 5; i++)
	    {
		sum = sum + arr[i];
	    }
	    average = sum / (float)n;
	    /*  Compute  variance  and standard deviation  */
	    for (int i = 0; i < n; i++)
	    {
		sum1 = sum1 + (arr[i] - average)*(arr[i] - average);
	    }
	    return sum1/(float)n;
}

int main()
{	
	int t=50;
	srand(time(0));
	int variance_in_waiting_times[t],variance_in_next_CPU_bursts[t],average_waiting_times[t];
	char buffer[1000000];
	for(int z=0;z<t;z++)
	{
		int btime=0,k=1,wt[100],sum=0,wsum=0,wavg=0,tsum=0,ta=0,tt[100],brst[100],tavg=0,min_arr=100;
		
		int n=rand()%9+1;
		//printf("number of processes:-\n\n:-%d" ,n);	

		struct node* head= NULL;
		
		for(int i=0;i<n;i++)
		{	
			head = append(head,"p",rand()%20,rand()%10);
		}
		struct node* temp = head;
		int time[10];
		bubbleSort(head);
		while(temp!=NULL)
		{
			if((temp->arrival) < min_arr)
			{
				min_arr = temp->arrival;	
			}
			temp=temp->next;
		}		
		temp=head;
		while(temp!=NULL)
		{
			//printf("\n\n\n\n%d\n\n\n" , min_arr);			
			temp->arrival= temp->arrival-min_arr;
			temp=temp->next;
		}		
		temp=head;
		for(int i=0;i<n;i++)
		{
			time[i]=temp->burst;
			temp=temp->next;	
		}
		struct node* min = head->next;
		struct node* min_2 = NULL;
		for(int j=0;j<n-1;j++)
		{
			btime = btime+time[j];
			//printf("%d" ,btime);
			min_2=min;
			while(min_2!=NULL)
			{
				if(btime>=min_2->arrival && min_2->burst<min->burst)
				{
					int temp = min->arrival; 
					min->arrival = min_2->arrival; 
					min_2->arrival = temp;
					temp = min->burst;
				 	min->burst = min_2->burst;
					min_2->burst = temp;
					char temp_arr[10];
					strcpy(temp_arr,min->name);
					strcpy(min->name,min_2->name);
					strcpy(min_2->name,temp_arr);
				}
				min_2=min_2->next;
			}
			min=min->next;
		}
		temp=head;
		wt[0]=0;
		while(temp->next!=NULL)
		{
			sum=sum+temp->burst;
			wt[k]=sum-((temp->next)->arrival);
			if(wt[k]<0)wt[k]=0;
			wsum=wsum+wt[k];
			k++;
			temp=temp->next;
		}
		temp=head;
		k=0;
		while(temp->next!=NULL)
		{
			brst[k] = temp->burst;
			k++;
			temp=temp->next;
		}
		temp=head;
		wavg=wsum/n;
		average_waiting_times[z]=wavg;	
		k=0;
		while(temp!=NULL)
		{
			ta=ta+temp->burst;
			tt[k]=ta-temp->arrival;
			tsum=tsum+tt[k];
			k++;
			temp=temp->next;	
		}
		tavg=tsum/n;
		temp=head;
		double var = variance(brst,n);
		variance_in_waiting_times[z]=var;
		
		var = variance(wt,n);
		variance_in_next_CPU_bursts[z]=var;
		printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
		k=0;
		while(temp!=NULL)
		{
			printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",temp->name,temp->burst,temp->arrival,wt[k],tt[k]);
			temp=temp->next;
			k++;
		}
		printf("\n\nAverage waiting time:-\t %d",wavg);
		printf("\nAverage turn-around time:-\t %d\n",tavg);
		free(min);
		free(min_2);			
		free(head);
		free(temp);
	}
	
	int binwidth = 5,sum=0;
	int average[200]	;

	for(int i=0;i<t/binwidth;i++)
	{
		sum=0;		
		for(int j=i*binwidth;j<(i+1)*binwidth;j++)
		{
			sum=sum+average_waiting_times[j];
		}
		average[i]  = sum/binwidth;
	}

	char * commandsForGnuplot1[] = {"plot 'plot_points.dat'"};
	char * commandsForGnuplot2[] = {
					"set style data histogram",
					"plot for [COL=2:2] 'plot_histogram.dat' using COL:xticlabels(1)"};
	FILE *fptr;
	fptr = fopen("plot_points.dat", "w");
	FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

	for(int i=0;i<t;i++)
	{
		fprintf(fptr,"%d       %d\n" , variance_in_next_CPU_bursts[i],variance_in_waiting_times[i]);
	}
	fclose(fptr);
	fptr = fopen("plot_histogram.dat","w");
	for(int i=0;i<t/binwidth;i++)
	{
		fprintf(fptr,"%d    %d\n" , i*binwidth,average[i]);
	}
	fclose(fptr);
	for (int i=0; i < 1; i++)
	{
		fprintf(gnuplotPipe, "%s \n", commandsForGnuplot1[i]); //Send commands to gnuplot one by one.
	}
	fclose(gnuplotPipe);
	gnuplotPipe = popen ("gnuplot -persistent", "w");
	for (int i=0; i < 1; i++)
	{
		fprintf(gnuplotPipe, "%s \n", commandsForGnuplot2[i]); //Send commands to gnuplot one by one.
	}
	fclose(gnuplotPipe);	
	return 0;
}
