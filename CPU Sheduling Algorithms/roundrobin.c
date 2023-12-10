#include<stdio.h>
#include<stdlib.h>
struct rr
{
    int pid,bT,wT,TAT,aT,rT,cT;
}p[50];
void main()
{
    int i,j,flag=0,n,tq,rem,time=0,min=0;
    float totwT=0,totTAT=0,cT=0;
    struct rr temp;
    printf("Enter the no.of Processes");
    scanf("%d",&n);
    rem=n;
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Enter the Arrival Time\n");
        scanf("%d",&p[i].aT);
        printf("Burst Time");
        scanf("%d",&p[i].bT);
        p[i].rT=p[i].bT;
        p[i].cT=p[i].aT;
    }
    printf("Enter the Time Quantum \n");
    scanf("%d",&tq);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].aT>p[j+1].aT)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    i=0;
    while(rem!=0)
    {
            if(p[i].rT<=tq && p[i].rT!=0)
            {
                time+=p[i].rT;
                p[i].rT=0;
                flag=1;
            }
            else if(p[i].rT>0)
            {
                p[i].rT=p[i].rT-tq;
                time+=tq;
            }
            if(p[i].rT==0 && flag==1)
            {
                rem--;
                p[i].TAT=time-p[i].aT;            
                p[i].wT=p[i].TAT-p[i].bT;
                totTAT+=p[i].TAT;
                totwT+=p[i].wT;
                p[i].cT=time;
                flag=0;
            }
            if(i==n-1)
            {
                i=0;
            }
            else if(p[i+1].aT<=time)
            {
                i++;
            }
            else
            {
                i=0;
            }
    }
for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].cT>p[j+1].cT)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("P\tAT\tBT\tWT\tTAT\tCT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].aT,p[i].bT,p[i].wT,p[i].TAT,p[i].cT);

    }
    printf("The average Waiting Time :%f\n",totwT/n);
    printf("The average Turn Around Time :%f\n",totTAT/n);
}