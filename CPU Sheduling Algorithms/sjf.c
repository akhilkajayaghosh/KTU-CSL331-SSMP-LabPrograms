#include<stdio.h>
struct sjf
{
    int pid,wt,bt,TAT,at,ct;
}p[15],temp[1];
void main()
{
    int n,i,j,cT=0;
    float totwt=0,totTAT=0;
    printf("Enter the no.of Processes:\n");
    scanf("%d",&n);
    printf("Enter the arrival and burst time:\n");
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Procces%d:\t",p[i].pid);
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
    p[0].wt=0;
    p[0].TAT=p[0].bt;
    for(i=0;i<n;i++)
    {
        int min=i;
        for(j=i;j<n;j++)
        {
            if(p[j].at<=cT && p[j].bt<p[min].bt)
                min=j;
        }
        if(min!=i)
        {
            temp[0]=p[min];
            p[min]=p[i];
            p[i]=temp[0];
        }
        p[i].wt=cT-p[i].at;
        p[i].TAT=p[i].wt+p[i].bt;
        cT+=p[i].bt;
        p[i].ct=cT;
        totwt+=p[i].wt;
        totTAT+=p[i].TAT;
    }
    printf("Process\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].TAT);
    }
    printf("Total Waiting time=%f\nTotal TAT=%f",totwt,totTAT);
    printf("Average Waiting time=%f\nAVerage TAT=%f",totwt/n,totTAT/n);
}