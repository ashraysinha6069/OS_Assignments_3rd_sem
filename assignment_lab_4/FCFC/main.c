#include<limits.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
struct pcb
{
	int arrivaltime,waittime,bursttime,nprocesses;
	//float varbursttime,varwaittime;
	struct pcb *next,*prev;
};
int main()
{
	FILE *f=fopen("inputdata.txt","r");
	FILE *o = fopen("outputdata","w+");					//for graph of variances
	FILE *o2 = fopen("realoutput.txt","w+");			//formated calculated values.
	int s,i,j;
	fscanf(f,"%d",&s);		//Read no. of sets of data present in input file.
	for(i=0;i<s;i++)
	{
						//		Make Linked List of PCBs
		int n;
		fscanf(f,"%d",&n);		//n stores no. of processes in current set. (first number in each line of input file)
		struct pcb *pcblist=NULL,*list=NULL;
		for(j=0;j<n;j++)
		{
			int arrivaltime,bursttime;
			fscanf(f,"%d %d",&arrivaltime,&bursttime);
			struct pcb *temp=(struct pcb*)malloc(sizeof(struct pcb));
			temp->bursttime=bursttime;
			temp->arrivaltime=arrivaltime;
			temp->waittime=0;
			//temp->varbursttime=temp->varwaittime=0.0;
			temp->nprocesses=n;
			temp->next=temp->prev=NULL;
			if(pcblist==NULL)
				pcblist=list=temp;
			else
			{
				list->next=temp;
				temp->prev=list;
				list=temp;
			}
		}
						//Displaying linked list:
		//for(list=pcblist;list!=NULL;list=list->next)
		//{
		//	printf("..%d..%d..->",list->arrivaltime,list->bursttime);
		//}
		//printf("\n");
						//Linked List of PCBs made. Now Algorithm time.
		int waitsum=0,burstsum=0,nprocesses=0,counter=0;
		float avgbursttime=0,avgwaittime=0;
		for(list=pcblist;list!=NULL;list=list->next)
		{
			if(list->prev==NULL)		//first Process
			{
				counter=list->arrivaltime+list->bursttime;
				list->waittime=0;
			}
			else
			{
				if(list->arrivaltime>counter)
				{
					counter=list->arrivaltime+list->bursttime;
					list->waittime=0;
				}
				else
				{
					list->waittime = counter-list->arrivaltime;
					counter+=list->bursttime;
				}
			}
			waitsum+=list->waittime;
			burstsum+=list->bursttime;
		}
		nprocesses=pcblist->nprocesses;
		avgwaittime=(float)waitsum/(float)nprocesses;
		avgbursttime=(float)burstsum/(float)nprocesses;
		float varwait=0,varburst=0;
		int minwait=INT_MAX,maxwait=0;
		for(list=pcblist;list!=NULL;list=list->next)
		{
			if(list->waittime>maxwait)
				maxwait=list->waittime;
			if(list->waittime<minwait)
				minwait=list->waittime;
			varwait+=(avgwaittime-(float)list->waittime)*(avgwaittime-(float)list->waittime);
			varburst+=(avgbursttime-(float)list->bursttime)*(avgbursttime-(float)list->bursttime);
		}
		varwait=varwait/nprocesses;
		varburst=varburst/nprocesses;
		fprintf(o,"%f\t%f\n",varburst,varwait);
		fprintf(o2,"Set:%d\t\tAvg WaitTime:%f\t\tVariance in WaitingTime%f\nMinimum WaitingTime:%d\tMaximum WaitingTime%d\n\n",i,avgwaittime,varwait,minwait,maxwait);
	}
	fclose(f);
	fclose(o);
}
