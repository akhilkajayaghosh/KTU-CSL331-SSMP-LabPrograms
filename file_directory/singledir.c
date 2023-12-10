#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct directory
{
	char dname[10], fname[10][10];
	int fc;
}dir;
void list()
{
	int i;
	printf("\nThe files in the directory %s are: ", dir.dname);
	for (i=0 ; i<dir.fc ; i++)
		printf("%s\t", dir.fname[i]);
}
void main()
{
	int i, ch;
	char f[10];
	dir.fc=0;
	printf("\nEnter the directory name: ");
	scanf("%s", &dir.dname);
	printf("\nMAIN MENU:");
	printf("\n1: Create a file");
	printf("\n2: Delete a file");
	printf("\n3: Search a file");
	printf("\n4: List the files");
	printf("\n5: Exit");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				y:
				printf("\nEnter the file to be created: ");
				scanf(" %s", &f);
				for (i=0 ; i<dir.fc ; i++)
				{
					if (strcmp(f, dir.fname[i]) == 0)
					{
						printf("\nFile name already exists");
						goto y;
					}
				}
				strcpy(dir.fname[dir.fc], f);
				dir.fc++;
				printf("\nFile creation successful");
				list();
				break;
			case 2:
				printf("\nEnter the file to be deleted: ");
				scanf(" %s", &f);
				for (i=0 ; i<dir.fc ; i++)
				{
					if (strcmp(f, dir.fname[i]) == 0)
					{
						printf("\nFile deletion successful");
						strcpy(dir.fname[i], dir.fname[dir.fc-1]);
						break;
					}
				}
				if (i==dir.fc)
					printf("\nFile %s not found", f);
				else
				{
					dir.fc--;
					list();
				}
				break;
			case 3:
				printf("\nEnter the file to be searched: ");
				scanf(" %s", &f);
				for (i=0 ; i<dir.fc ; i++)
				{
					if (strcmp(f, dir.fname[i]) == 0)
					{
						printf("File %s found\n", f);
						break;
					}
				}
				if (i==dir.fc)
					printf("File %s not found\n", f);
				break;
			case 4:
				list();
				break;
			case 5:
				printf("Exiting the menu\n");
				exit(0);
			default:
				printf("\nPlease enter a valid choice");
		}
	}
}
