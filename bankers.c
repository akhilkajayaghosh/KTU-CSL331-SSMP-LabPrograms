#include<stdio.h>
void main()
{
    int np,nr,i,j;
    printf("Enter the no.of Process and resorces");
    scanf("%d%d",&np,&nr);
    int flag[np],ans[np];
    int alloc[np][nr],max[np][nr],need[np][nr];
    int avail[nr];
    printf("Enter allocation matrix\n");
    for(i=0;i<np;i++)
    {
        for(j=0;j<nr;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter Max matrix\n");
    for(i=0;i<np;i++)
    {
        for(j=0;j<nr;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available resources\n");
    for(i=0;i<nr;i++)
        scanf("%d",&avail[i]);
    for(i=0;i<np;i++)
    {
        for(j=0;j<nr;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(i=0;i<np;i++)
       flag[i]=0;
    printf("Need Matrix\n");
    for(i=0;i<np;i++)
    {
        for(j=0;j<nr;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    int k,index=0,f;
    for(k=0;k<np;k++)
    {
        for(i=0;i<np;i++)
        {
            f=0;
            if(flag[i]==0)
            {
                for(j=0;j<nr;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f==0)
                {
                    ans[index++]=i;
                    flag[i]=1;
                    for(j=0;j<nr;j++)
                    {
                        avail[j]+=alloc[i][j];
                    }
                }
            }
        }
    }
    f=0;
    for(i=0;i<np;i++)
    {
        if(flag[i]==0)
        {
            printf("Unsafe State!!");
            f=1;
            break;
        }
    }
    if(f==0)
    {
        printf("Safe State");
        for(i=0;i<np;i++)
        {
            if(i==np-1)
            {
                printf("P%d",ans[i]);
            }
            else
            {
                printf("P%d-->",ans[i]);
            }
        }        
    }
}