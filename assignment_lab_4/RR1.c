#include <stdio.h>
#include<stdlib.h>

struct process
{
    char name;
    int at, bt, wt, tt, rt;
    int completed;
} p[10];

int n;
int q[10];
int front = -1, rear = -1;
void enqueue(int i)
{
    if (rear == 10)
        printf("Full");
    else
    {
        rear++;
        q[rear] = i;
    }
    if (front == -1)
        front = 0;
}

int dequeue()
{
    if (front == -1)
        printf("Empty");
    int temp = q[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return temp;
}

int isInQueue(int i)
{
    int k;
    for (k = front; k <= rear; k++)
    {
        if (q[k] == i)
            return 1;
    }
    return 0;
}

void sortByArrival()
{
    struct process temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
}

void main()
{
    int i, j, time = 0, sum_bt = 0, tq,cs=0;
    char c;
    FILE *fp1,*fp2;
    fp1=fopen("mojo.txt","w");
    fp2=fopen("input.txt","r");
    // int ntq;
    // printf("\nEnter the no. of time quantum:");
    // scanf("%d", &ntq);
    // for(int r=0;r<ntq;r++)
    // {
    float avgwt = 0;
    //printf("Enter no of processes:");
    fscanf(fp2,"%d", &n);
    
    for (i = 0, c = 'A'; i < n; i++, c++)
    {
        p[i].name = c;
       // printf("\nEnter the arrival time and burst time of process %c: ", p[i].name);
        fscanf(fp2,"%d%d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].completed = 0;
        sum_bt += p[i].bt;
    }
   
    printf("Enter Time Quantum value:");
    scanf("%d",&tq);
    sortByArrival();
    enqueue(0); 
    //printf("Process execution order: ");
    for (time = p[0].at; time < sum_bt;) 
    {
        i = dequeue();
        if (p[i].rt <= tq)
        {                 
            time += p[i].rt;
            p[i].rt = 0;
            p[i].completed = 1;
            printf(" %c ", p[i].name);
            cs++;
            p[i].wt = time - p[i].at - p[i].bt;
            p[i].tt = time - p[i].at;
            for (j = 0; j < n; j++)   
            {
                if (p[j].at <= time && p[j].completed != 1 && isInQueue(j) != 1)
                {
                    enqueue(j);
                }
            }
        }
        else 
        {
            time += tq;
            p[i].rt -= tq;
            printf(" %c ", p[i].name);
            cs++;
            for (j = 0; j < n; j++)              
            {
                if (p[j].at <= time && p[j].completed != 1 && i != j && isInQueue(j) != 1)
                {
                    enqueue(j);
                }
            }
            enqueue(i); 
        }
    }
    printf("\nNo. of context switches:%d ",cs);
    fprintf(fp1,"\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");
    for (i = 0; i < n; i++)
    {
        avgwt += p[i].wt;
        fprintf(fp1,"\n%c\t\t%d\t\t%d\t\t%d\t\t%d", p[i].name, p[i].at, p[i].bt, p[i].wt, p[i].tt);
    }
        fprintf(fp1,"\nAverage waiting time:%f\t%d", avgwt / n,tq);
        //fprintf(fp2,"\n%f\t%d\n",avgwt/n,tq);
//}
}
