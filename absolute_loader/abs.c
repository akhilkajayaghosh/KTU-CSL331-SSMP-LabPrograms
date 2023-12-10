#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  FILE *f;
  f=fopen("objectcode.txt","r");
  int i,addr1,j,staddr1;
  char name[10],line[50],name1[10],addr[10],staddr[10];
  printf("Enter the program name:");
  scanf("%s",name);
  fscanf(f,"%s",line);
  for(i=2,j=0;i<6,j<4;i++,j++)
    {
      name1[j]=line[i];
    }name1[j]='\0';
  if(strcmp(name,name1)==0)
  {
    printf("Program name verified\n");
    fscanf(f,"%s",line);
    do
      {
        if(line[0]=='T')
        {
          for(i=2,j=0;i<8,j<6;i++,j++)
            {
              staddr[j]=line[i];
            }
          staddr[j]='\0';
          staddr1=atoi(staddr);
          i=12;
          while(line[i]!='$')
            {
              if(line[i]!='^')
              {
                printf("00%d\t%c%c\n",staddr1,line[i],line[i+1]);
                staddr1++;
                i=i+2;
              }
              else
                i++;
            }
        }
        else if(line[0]=='E')
        {
          fclose(f);
          exit(0);
        }
         fscanf(f,"%s",line);
      }
      while(!(feof(f)));
  }
}
