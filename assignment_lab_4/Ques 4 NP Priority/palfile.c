#include<stdio.h>
#include<stdlib.h>

int n;

struct process
{
	char name;
	int at,bt,ct,wt,tt,priority;
	int processed;

};

struct Node{
	struct process p[100];
	struct Node* next;
};

void append(struct Node** head_ref, char name , int at , int bt , int priority,int i) 
{ 
    struct Node* new_node;
    if(i==0){
	  new_node = (struct Node*) malloc(sizeof(struct Node)); 
	  }else{
		new_node = *head_ref ;
}
 
    new_node->p[i].name  = name; 
    new_node->p[i].at  = at; 
    new_node->p[i].bt  = bt; 
    new_node->p[i].priority  = priority; 
  
    new_node->p[i].processed=0;
    new_node->next = NULL; 
  
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
  
  
    return; 
} 
void sortByArrival(struct Node** head)
{
	struct Node* temp;
	temp = (struct Node*) malloc(sizeof(struct Node));
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
	if((*head)->p[i].at>(*head)->p[j].at)
	{
	temp->p[99]=(*head)->p[i];
	(*head)->p[i]=(*head)->p[j];
	(*head)->p[j]=temp->p[99];
	}
        }
}



void main()
{
	int g;
	FILE* fp,*fpr;
	fp = fopen("input5.txt","r");
	fpr = fopen("output.txt","w");

	for(g=0;g<60;g++){
	float var=0,avgbt=0;
	struct Node* head = NULL;
	int i,j=0,time=0,sum_bt=0,largest,e,f,h;
	char c;
		float avgwt=0;
	 fscanf(fp,"%d\n",&n);
	 for(i=0,c='A';i<n;i++,c++)
	 {

	 fscanf(fp,"%d\t%d\t%d\n",&e,&f,&h);
	append(&head,c,e,f,h,i);

	 sum_bt+=f;
	 
	 
	}

	avgbt= sum_bt/n;
	fprintf(fpr,"%f\t",avgbt);
	sortByArrival(&head);

	head->p[9].priority=-9999;
	printf("Gnatt Chart\n");
  for(time=head->p[0].at;time<sum_bt;)
  {
	    largest=9;
	    for(i=0;i<n;i++)
	    {
	      if(head->p[i].at<=time && head->p[i].processed!=1 && head->p[i].priority>head->p[largest].priority)
		largest=i;
    }
	      time+=head->p[largest].bt;
	  head->p[largest].ct=time;
		  head->p[largest].wt=head->p[largest].ct-head->p[largest].at-head->p[largest].bt;
	     head->p[largest].tt=head->p[largest].ct-head->p[largest].at;
	    
	    head->p[largest].processed=1;
	    
	    avgwt+=head->p[largest].wt;
    
	if(j==0){
		printf("%d---",head->p[largest].at) ;
			j++ ;
	}
	printf("P%d---%d---",largest+1, head->p[largest].ct);
	}

	for(i=0;i<n;i++){
		var+=(head->p[i].wt-(avgwt/n))*(head->p[i].wt-(avgwt/n));
	}

	printf("\nAverage waiting time:%f\n",avgwt/n);
	fprintf(fpr,"%f\n",avgwt/n);
	printf("\nVariance:%f\n",var/n);
	free(head);
}

}
