#include<stdio.h>
struct process
{
    int id;//process id
    int at;//arrival time
    int st;//starting time
    int bt;//burst time
    int copyofbt;//copy of burst timeŝ
    int et;//completion time of process
};
struct process hc[100];

/**function to find minimum remaining time for the processes that have arrived by t**/
int min(int t,int n)
{
    int i,k=-1;
    int min=1000;
    for(i=0;i<n;i++)
    {
        if(hc[i].at<=t && hc[i].bt!=0)
        {
                if(hc[i].bt<min)
                {
                    min=hc[i].bt;
                    k=i;
                }
        }
    }
    return k;
}

void main()
{
    int i,n,k,j,wt,tt;
    float awt,att;
    int number_of_process_executed=0;
    int harish[1000];//array to hold processes executed at every second ith element involves id of process being executed at ith second
    printf("Enter number of processes\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        hc[i].st=-1;//initializing starting time of every process to one

    printf("Enter id,arrival time and burst time of each process one bye one:\n");
    printf("Pid A B\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&hc[i].id,&hc[i].at,&hc[i].bt);
        hc[i].copyofbt=hc[i].bt;
    }
    for(i=0,j=0;;i++)
    {
        if(number_of_process_executed==n)
            break;
        k=min(i,n);
        harish[j++]=hc[k].id;
        hc[k].bt--;
        if(hc[k].bt==0)
        {
            number_of_process_executed++;
            hc[k].et=i+1;//process will execute during this ith second and would complete at i+1
        }
    }
    k=-1;
    for(i=0;i<j;i++)
    {
        if(harish[i]!=k)//if the current executing process is not the same as the previous one
        {
            if(hc[harish[i]].st==-1)//process is executing for the first time
            {
                hc[harish[i]].st=i;//setting its starting time
                k=harish[i];
            }
        }
    }

    /*** Printing ***/

    /**printing upper line of rectangle**/
    k=-1;
    for(i=0;i<j;i++)
    {
        if(harish[i]!=k)//if the current executing process is not the same as the previous one.
        {
            printf("_______");
            k=harish[i];
        }
    }
    printf("\n");
    /**Printing process names and vertical lines and lower line**/
    k=-1;
    for(i=0;i<j;i++)
    {
        if(harish[i]!=k)//if the current executing process is not the same as the previous one.
        {
            printf("|__P%d__",harish[i]);
            k=harish[i];
        }
    }
    printf("|\n");

    /** pinting time**/
    k=-1;
    for(i=0;i<j;i++)
    {
        if(harish[i]!=k)//if the current executing process is not the same as the previous one.
        {
            printf("%d      ",i);
            k=harish[i];
        }
    }
    printf("%d      \n",i);

    /** Calculating and printing waiting and turnaround time**/
    printf("Process\tWaitingTime\tTurnAroundTime\n");
    for(i=0,awt=0,att=0;i<n;i++)
    {
        wt=(hc[i].st-hc[i].at)+(hc[i].et-hc[i].st-hc[i].copyofbt);//time to wait before starting + time of wait during preemption
        tt=(hc[i].et-hc[i].at);
        printf("%d\t%d\t%d\n",hc[i].id,wt,tt);
        awt+=wt;
        att+=tt;
    }
    awt=awt/n;
    att=att/n;
    printf("\n");
    printf("Average waiting time is: %0.2f\n",awt);
    printf("Average turn around time is: %0.2f\n",att);
}
