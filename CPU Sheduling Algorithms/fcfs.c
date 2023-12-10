#include<stdio.h>
struct fcfs
{
    int pid,wt,bt,TAT,at;
}p[15],temp[15];
void main()
{
    int n,i,j;
    float totwt=0,totTAT=0;
    printf("Enter the no.of Processes:\n");
    scanf("%d",&n);
    printf("Enter the arrival and burst time:\n");
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Procces%d",p[i].pid);
        scanf("%d%d",&p[i].at,&p[i].bt);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].at>p[j].at)
            {
                temp[0]=p[i];
                p[i]=p[j];
                p[j]=temp[0];
            }
        }
    }
    printf("Process\tAT\tBT\tWT\tTAT\n");
    p[0].wt=0;
    p[0].TAT=p[0].bt-p[0].at;
    for(i=1;i<n;i++)
    {
        p[i].wt=p[i-1].wt+p[i-1].bt+p[i-1].at-p[i].at;
        p[i].TAT=p[i].wt+p[i].bt;
        totwt+=p[i].wt;
        totTAT+=p[i].TAT;
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].TAT);
    }
    printf("Total Waiting time=%f\nTotal TAT=%f",totwt,totTAT+p[0].TAT);
    printf("Average Waiting time=%f\nAVerage TAT=%f",totwt/n,(totTAT+p[0].TAT)/n);
}