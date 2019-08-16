#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
char *list[101];
int count=0;
int checkname(char s[50]){
    int length=strlen(s)-1;
    int i;
    for (i=0;i<=length;i++)
        if (s[i]>='A' && s[i]<='Z') return 1;
    return 0;
}
int checknum(char s[10])
{
	int length=strlen(s)-1;
	int i;
	for (i=0;i<=length;i++)
		if(s[i]<'0'||s[i]>'9') return 0;
	return 1;
}
int convert(char s[10])
{
	int num=0;
	int length=strlen(s)-1;
	int i;
	int now=1;
	for (i=length;i>=0;i--)
	{
		num+=(s[i]-'0')*now;
		now*=10;
	}
	return num;
}
char* ltrim(char s[])
{
	int i=0;
	while (s[i]==' ') i++;
	if (i>0) strcpy(&s[0],&s[i]);
	return s;
}
char* rtrim(char s[])
{
	int i=strlen(s)-1;
	while (s[i]==' ')i--;
	s[i+1]='\0';
	return s;
}
char *trim(char s[])
{
	rtrim(ltrim(s));
	char *pt=strstr(s," ");
	while(pt!=NULL)
	{
		strcpy(pt,pt+1);
		pt=strstr(s," ");
	}
	return s;
}
int menu()
{
	printf("\n++++++++++++++++++++++++++++++\n");
    printf("1:Add a student\n");
    printf("2:Remove a student\n");
    printf("3:Search a student\n");
    printf("4:Print the list in ascending oder\n");
    printf("5:Quit\n");
    printf("++++++++++++++++++++++++++++++\n");
    int check=-1;
    char s[10];
    do
    {
    	printf("Your choice:");
    	scanf("%s",s);
    	check=checknum(s);
	}
	while (check==0);
	int a=convert(s);
	return a;
}
void add()
{
	printf("Enter number of student:");
	scanf("%d",&count);
	getchar();
	int i;
	int check=-1;
	for (i=1;i<=count;i++)
	{
		do{
		printf("%d/",i);
		char s[50];
		gets(s);
		trim(s);
		strupr(s);
		check=checkname(s);
		strcpy(list[i],s);
		} while (check==0);
	}
}
void add1()
{
	printf("Enter the student you want to add ");
	getchar();
	int check=-1;
	count++; 
	do{
		gets(list[count]);
		trim(list[count]);
		strupr(list[count]);
		check=checkname(list[count]);
		} while (check==0);
}
void removeS()
{
	printf("Enter the student you want to remove ");
	getchar();
	char s[50];
	gets(s);
	trim(s);
	strupr(s);
	int i;
	int flag=0;
	for(i=1;i<=count;i++)
		if(strcmp(s,list[i])==0) 
		{
			flag=i;
			break;
		}
	if (flag==0) printf("Not found!\n");
	else{
	for (i=flag;i<=count-1;i++)
			strcpy(list[i],list[i+1]);
	list[count]=NULL;
	count--;
	}
}
void search()
{
	printf("Enter the student you want to search ");
	getchar();
	char s[50];

	gets(s);
	trim(s);
	strupr(s);
//		printf("\n%s", s);
	int i;
	int flag=0;
	for(i=1;i<=count;i++)
	
		if(strcmp(s,list[i])==0)
		{
			flag = i;
			break;
		} 
	if(flag!=0) printf("At %d",flag);
	else printf("Student name can not be found ");
}
void sort()
{
	char *s[50];
	int i,j;
	for(i=1;i<count;i++)
		for (j=i+1;j<=count;j++) if(strcmp(list[i],list[j])==1)
			{
				s[50]=list[i];
				list[i]=list[j];
				list[j]=s[50];
			}
}
int main()
{
	int i;
	for (i=1;i<101;i++)
        list[i]=(char*)malloc(50);
    int choice;
    do
    {
        choice=menu();
        switch (choice)
        {
        case 1: if (count==0) add();
        		else add1();
        		break;
        case 2: if (count!=0) 
				{
				removeS();
        		for (i=1;i<=count;i++) printf("%d/%s\n",i,list[i]);
        		}
				break;
        case 3: if (count!=0) search();
				break;
        case 4: if (count!=0) 
        		{
					sort();
					for (i=1;i<=count;i++) printf("%d/%s\n",i,list[i]);
				}
				break;
        default: break;
        }
    } while (choice>=1 && choice<=5);
}

