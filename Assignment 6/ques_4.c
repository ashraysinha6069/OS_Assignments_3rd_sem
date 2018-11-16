#include<stdio.h>
#include<stdlib.h>

struct node{
	int pageno;
	struct node* next;
};

struct node *front;
struct node *rear;

void enqueue(int value)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));

	temp->pageno=value;
	temp->next=NULL;
	rear->next=temp;
	rear=temp;
	return;	
}

void dequeue()
{
	struct node* temp;
	temp=front->next;
	front=temp;
	return;
}

int present(int value)
{
	int answer=0;
	struct node* temp;
	temp=front;
	while(temp!=NULL)
	{
		if(temp->pageno==value)
		{
			answer=1;
			break;
		}
		temp=temp->next;
	}
	return answer;
}

void printQ()
{
	struct node* temp;
	temp=front;
	while(temp!=NULL)
	{	
		printf("%d ",temp->pageno);
		temp=temp->next;
	}
	printf("\n");
	return;
}

int main()
{

	long int noofpages;
	int frames;
	printf("enter the string length: ");
	scanf("%ld",&noofpages);
	int string[noofpages];
	long int i;

	printf("enter the string of length %ld- ",noofpages);
	for(i=0;i<noofpages;i++)
		scanf("%d",&string[i]); 
	printf("enter the no. of allocated frames: ");
	scanf("%d",&frames);

	long int pf;

	//enqueue(string[0]);
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->pageno=string[0];
	temp->next=NULL;
	front=temp;
	rear=front;
	printQ();

	pf=1; 
	int size=1;
	long int ls;
	ls=noofpages-1; //leftstring

	int j=1;
	
	while(ls!=0)
	{
		if(!present(string[j]) && size!=frames)
		{
			enqueue(string[j]);
			pf++;
			size++;
		}
		else if(!present(string[j]) && size==frames)
		{
			dequeue(string[j]);
			enqueue(string[j]);
			pf++;
		}
		printQ();
		ls--;
		j++;
	}

	printf("no of page faults in FIFO page replacement algo: %ld\n",pf);
	return 0;

}
