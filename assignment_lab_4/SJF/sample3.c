    #include<stdio.h>
     
    struct process
    {
     int arr_time;
     int burst_time;
     int no;
     int rem_time;
     int priority;
    };
     
     
    struct process read(int i)
    {
     struct process p;
     printf("\n\n The process no.:%d.\n",i);
     p.no=i;
     printf("Enter the arrival time:");
     scanf("%d",&p.arr_time);
     printf("Enter the burst time:");
     scanf("%d",&p.burst_time);
     p.rem_time=p.burst_time;
     return p;
    }
     
     
     
    struct process readp(int i)
    {
     struct process p;
     printf("\n\n The process no.:%d.\n",i);
     p.no=i;
     printf("Enter the arrival time:");
     scanf("%d",&p.arr_time);
     printf("Enter the burst time:");
     scanf("%d",&p.burst_time);
     p.rem_time=p.burst_time;
     printf("Enter the priority:");
     scanf("%d",&p.priority);
     return p;
    }
     
     
     
    void swap(struct process *i, struct process *j)
    {
     struct process *t;
     i=t;
     i=j;
     j=t;
    }
     
     
     
    //SHORTEST JOB FIRST SCHEDULING ALGO.
     
    int main()
    {
     int  n;        //To hold the no. of processes.
     struct process p[10],tmp;     //To hold the details of the processes.
     int i,j;
     int ready[10];       //List of ready processes  index
     int running;       //Running process index
     int t;        //Time variable
     int last,min;
     int time;
     printf("Enter the number if processes you want to enter:");
     scanf("%d",&n);
     
     
     for(i=0;i<n;i++)
      p[i]=read(i);      //Read the details of the processes
     
     t=0;
     last=-1;
     min=0;
     time=0;
     
     do
     {
      last=-1;
      for(i=0;i<n;i++)
      {
       if(p[i].arr_time<=time && p[i].rem_time>0)
       {
        ready[++last]=i;   //update the ready queue
        
       }
     
      }
     
      min = ready[0];
      if(last<0)
       continue;
      for(i=0;i<=last;i++)
      {
       if(p[ready[i]].rem_time<p[min].rem_time)
        min=ready[i];
      }
      running = min;      //Schedule a process and print the process that was scheduled
      printf("\n\nTime:%d to time: %d Running Process: %d",time,time+p[running].rem_time,running);
      
      time = time + p[running].rem_time;
      p[running].rem_time=0;     //Remove the process from the ready queue
      
     
       
     }while(last>=0);
     printf("\n"); 
     return 0;
    }
