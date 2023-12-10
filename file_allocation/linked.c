#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i, j, n, mem[100], alloc[20], sb[20], b[20], count=0, ch, k, success;
	for (i=0 ; i<100 ; i++)
		mem[i]=0;
	for (i=0 ; i<20 ; i++)
	{
		alloc[i]=0;
		sb[i]=0;
		b[i]=0;
	}
	printf("\nEnter the number of blocks already allocated: ");
	scanf("%d", &n);
	printf("\nEnter the already allocated blocks:\n");
	for (i=0 ; i<n ; i++)
	{
		scanf("%d", &alloc[i]);
		mem[alloc[i]]=alloc[i];
	}
	do
	{
		count++;
		success=0;
		printf("\nEnter the number of blocks occupied by file %d: ", count);
		scanf("%d", &b[count]);
		printf("\nEnter the starting block of file %d: ", count);
		scanf("%d", &sb[count]);
		k=sb[count];
		while (success!=b[count])
		{
			if (mem[k] == 0)
			{
				mem[k]=k;
				printf("Block %d has been allocated for file %d\n", k, count);
				k++;
				success++;
			}
			else
			{
				printf("Block %d is already allocated\n", k);
				k++;
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
