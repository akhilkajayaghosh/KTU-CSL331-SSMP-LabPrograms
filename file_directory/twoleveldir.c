#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct directory
{
	char dname[10], fname[10][10];
	int fc;
}dir[100];
int dc=0;
void list()
{
	int i, j;
	printf("\n\nThe directories in the system are,");
	for (i=0 ; i<dc ; i++)
	{
		printf("\nDirectory Name: %s\n", dir[i].dname);
		if (dir[i].fc != 0)
		{
			printf("The files in the directory %s are: ", dir[i].dname);
			for (j=0 ; j<dir[i].fc ; j++)
				printf("%s\t", dir[i].fname[j]);
			printf("\n");
		}
		else
			printf("No files created yet\n");
	}
}
void main()
{
	int i, j, ch, flag;char d[10], f[10];
	for (i=0 ; i<100 ; i++)
		dir[i].fc=0;
	printf("\nMAIN MENU:");
	printf("\n1: Create a directory");
	printf("\n2: Create a file");
	printf("\n3: Delete a file");
	printf("\n4: Search a file");
	printf("\n5: List the files");
	printf("\n6: Exit");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				x:
				printf("\nEnter the directory name: ");
				scanf(" %s", &d);
				for (i=0 ; i<dc ; i++)
				{
					if (strcmp(d, dir[i].dname) == 0)
					{
						printf("Directory name already exists");
						goto x;
					}
				}
				strcpy(dir[dc].dname, d);
				dc++;
				printf("Directory creation successful");
				list();
				break;
			case 2:
				flag=0;
				printf("\nEnter the directory name: ");
				scanf(" %s", &d);
				for (i=0 ; i<dc ; i++)
				{
					if (strcmp(d, dir[i].dname) == 0)
					{
						flag=1;
						y:
						printf("\nEnter the file to be created: ");
						scanf(" %s", &f);
						for (j=0 ; j<dir[i].fc ; j++)
						{
							if (strcmp(f, dir[i].fname[j]) == 0)
							{
								printf("File name already exists\n");
								goto y;
							}
						}
						strcpy(dir[i].fname[dir[i].fc], f);
						dir[i].fc++;
						printf("File creation successful");
						list();
						break;
					}
				}
				if (flag==0)
					printf("Directory %s not found\n", d);break;
			case 3:
				flag=0;
				printf("\nEnter the directory name: ");
				scanf(" %s", &d);
				for (i=0 ; i<dc ; i++)
				{
					if (strcmp(d, dir[i].dname) == 0)
					{
						flag=1;
						printf("\nEnter the file to be deleted: ");
						scanf(" %s", &f);
						for (j=0 ; j<dir[i].fc ; j++)
						{
							if (strcmp(f, dir[i].fname[j]) == 0)
							{
								printf("File deletion successful");
								strcpy(dir[i].fname[j],dir[i].fname[dir[i].fc-1]);
								break;
							}
						}
						if (j==dir[i].fc)
							printf("File %s not found\n", f);
						else
						{
							dir[i].fc--;
							list();
						}
					}
				}
				if (flag==0)
					printf("Directory %s not found\n", d);
				break;
			case 4:
				flag=0;
				printf("\nEnter the directory name: ");
				scanf(" %s", &d);
				for (i=0 ; i<dc ; i++)
				{
					if (strcmp(d, dir[i].dname) == 0)
					{
						flag=1;
						printf("\nEnter the file to be searched: ");
						scanf(" %s", &f);
						for (j=0 ; j<dir[i].fc ; j++)
						{
							if (strcmp(f, dir[i].fname[j]) == 0)
							{
								printf("File %s found\n", f);
								break;
							}
						}
						if (j==dir[i].fc)
							printf("File %s not found\n", f);
					}
				}
				if (flag==0)
					printf("Directory %s not found\n", d);
				break;
			case 5:
				list();
				break;
			case 6:
				printf("Exiting the menu\n");
				exit(0);
			default:
				printf("\nPlease enter a valid choice");
		}
	}
}
