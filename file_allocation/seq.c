#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n, i, j, b[20], sb[20], mem[100], ch, count=0;
	for (i=0 ; i<100 ; i++)
		mem[i]=0;
	for (i=0 ; i<20 ; i++)
	{
		b[i]=0;
		sb[i]=0;
	}
	do
	{
		count++;
		printf("\nEnter the number of blocks occupied by file %d: ", count);
		scanf("%d", &b[count]);
		x:
		printf("\nEnter the starting block of file %d: ", count);
		scanf("%d", &sb[count]);
		for (j=sb[count] ; j<(sb[count]+b[count]) ; j++)
		{
			if (mem[j] == 0)
			{
				mem[j]=j;
				printf("Block %d has been allocated for file %d\n", j, count);
			}
			else
			{
				printf("\nBlock %d is already allocated", j);
				printf("\nTry again!!\n");
				for (int k=sb[count] ; k<j ; k++)
					mem[k]=0;
				goto x;
			}
		}
		printf("\nFile Allocation Successful\n");
		printf("\nPress 1 to continue allocation, Press 0 to stop allocation: ");
		scanf("%d", &ch);
	}
	while (ch==1);
	printf("\nFile\tStart\tBlock Length\n");
	for (j=1 ; j<=count ; j++)
		printf("%2d%9d%10d\n", j, sb[j], b[j]);
}
