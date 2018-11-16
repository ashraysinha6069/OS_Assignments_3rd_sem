
#include <bits/stdc++.h>
using namespace std;
 
struct Process {
    int pid; // Process ID
    int bt; // Burst Time
    int art; // Arrival Time
    int pr; //Priority
};
 

void findWaitingTime(Process proc[], int n,
                                int wt[])
{
    int rt[n];
 

    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;
 
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    int k=-1;

    int m=shortest;
  
    while (complete != n) {
 
       
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) &&
            (proc[j].pr<minm) && rt[j] > 0) {
                minm = proc[j].pr;
                shortest = j;
                check = true;
		k++;
            }
        }
	if(check==true && k==0){
		printf("%d---",t);
	}	
	if(shortest!=m || k==0){
		printf("P%d---%d---",proc[shortest].pid,t);
		m=shortest;
	
	}
 
        if (check == false) {
            t++;
            continue;
        }
 

        rt[shortest]--;
 
        if (rt[shortest] == 0)
            minm = INT_MAX;
 


        if (rt[shortest] == 0) {
 

            complete++;
 
            finish_time = t + 1;
 

            wt[shortest] = finish_time -
                        proc[shortest].bt -
                        proc[shortest].art;
 
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        t++;
    }
}
 

void findTurnAroundTime(Process proc[], int n,
                        int wt[], int tat[])
{

    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}
 

void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0,
                    total_tat = 0;
 

    findWaitingTime(proc, n, wt);
 
   
    findTurnAroundTime(proc, n, wt, tat);
 
 
    cout << "Processes "
        << " Burst time "
	<< " Priority "
        << " Waiting time "
        << " Turn around time\n";
 
   
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        
    }
 
    cout << "  Average waiting time = "
        << (float)total_wt / (float)n;
    cout << "  Average turn around time = "
        << (float)total_tat / (float)n <<endl;
}
 

int main()
{
    Process proc[] = { {1,6,1,3}, {2,8,1,1 },
                    { 3,7,2,2 },{ 4,3,3,4 } };
    int n = sizeof(proc) / sizeof(proc[0]);
 
    findavgTime(proc, n);
    return 0;
}
