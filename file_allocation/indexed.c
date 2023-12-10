#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i, j, n, mem[100], index, b[20], block[20], count=0, ib[20], ch;
	for (i=0 ; i<100 ; i++)
	{
		mem[i]=0;
		ib[i]=0;
	}
	for (i=0 ; i<20 ; i++)
	{
		block[i]=0;
		b[i]=0;
	}
	do
	{
		count++;
		printf("\nEnter the index block of the file %d: ", count);
		x:
		scanf("%d", &index);
		ib[count]=index;
		if (mem[index] == 0)
		{
			mem[index]=1;
			printf("Block %d has been allocated as index block for file %d\n", index,count);
		}
		else
		{
			printf("\nBlock %d is already allocated\n", index);
			printf("\nEnter another block for index: ");
			goto x;
		}
		printf("\nEnter the number of blocks occupied by file %d: ", count);
		scanf("%d", &b[count]);
		printf("\nEnter the blocks:\n");
		for (i=0 ; i<b[count] ; i++)
		{
			y:
			scanf("%d", &block[i]);
			if (mem[block[i]]==0)
				mem[block[i]]=block[i];
			else
			{
				printf("\nBlock %d is already allocated\n", block[i]);
				printf("\nEnter another block: ");
				goto y;
			}
		}
		printf("\nFile Allocation Successful\n");
		printf("\nPress 1 to continue allocation, Press 0 to stop allocation: ");
		scanf("%d", &ch);
	}
	while (ch==1);
	printf("\nFile\tIndex\tBlock Length\n");
	for (j=1 ; j<=count ; j++)
		printf("%2d%9d%10d\n", j, ib[j], b[j]);
}
