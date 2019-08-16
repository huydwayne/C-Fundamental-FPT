#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int count=0;
struct employee{
    char id[30];
    char name[30];
    char skill[30];
    char hobbies[30];
    struct birthdate 
	{
    int day;
    int month;
    int year;
	}date;    
};
struct employee listdata[100];
int checkname(char s[20]){
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
        if (s[i]<'0' || s[i]>'9') return 0;
    return 1;
}
int valid_Date(int day,int month, int year)
{
	int maxd=31;
	if (year>2019||year<1919) return 0;
	if (day<1||day>31||month<1||month>12||year==0) return 0;
	if (month==4 || month ==6 || month==9 ||month==11) maxd=30;
	else if(month==2)
	{
		if(year%400==0||year%4==0 && year%100!=0) maxd=29;
		else maxd=28;
	}
	return day<=maxd;
}
int convert(char s[10])
{
    long ans=0;
    int length=strlen(s)-1;
    int now=1;
	int i; 
    for (i=length;i>=0;i--)
    {
        ans+=(s[i]-'0')*now;
        now*=10;
    }
    return ans;
}
char* ltrim(char s[]){
    int i=0;
    while (s[i]==' ') i++;
    if (i>0) strcpy(&s[0],&s[i]);
    return s;
}
char* rtrim(char s[]){
    int i=strlen(s)-1;
    while (s[i]==' ') i--;
    s[i+1]='\0';
    return s;
}
char* trim(char s[]){
    rtrim(ltrim(s));
    char *pt=strstr(s,"  ");
    while (pt!=NULL)
    {
        strcpy(pt,pt+1);
        pt=strstr(s,"  ");
    }
    return s;
}
char* nameStr (char s[])
{
	trim(s);
	strlwr(s);
	int L = strlen(s);
	int i,n;
	for (i=0;i<L;i++)
		if (i==0|| (i>0 && s[i-1]==' ')) s[i]= toupper(s[i]);
	return s;
}
void input()
{
    printf("Enter number of employee:");
    scanf("%d",&count);
    getchar();
    int check=-1;
    char s[10];
    int i,n;
    for (i=1;i<=count;i++)
    {	printf("Employee %d:\n",i);
    	do{
    		check = -1;
			printf("-Input id:");gets(listdata[i].id);trim(listdata[i].id);
    		for(n=1;n < i;n++)
			{	
				if (strcmp(listdata[n].id,listdata[i].id)==0) check=0;
			}
    	}while(check==0);
    	do{
    	printf("-Input name:");gets(listdata[i].name);nameStr(listdata[i].name);
    	} while(checkname(listdata[i].name)==0);
    	do{	
			printf("-Input birthday:\n");
    		do {
				printf("Date:");scanf("%s",s);check=checknum(s);
				listdata[i].date.day=convert(s);
			}
			while (check==0);check=-1;
    		do {
				printf("Month:");scanf("%s",s);check=checknum(s);
				listdata[i].date.month=convert(s);
			} 
			while (check==0);check=-1;
    		do {
				printf("Year:");scanf("%s",s);check=checknum(s);
				listdata[i].date.year=convert(s);
			} 
			while (check==0);
		}
		while(valid_Date(listdata[i].date.day,listdata[i].date.month,listdata[i].date.year)==0);getchar();
    	printf("-Input skill:");gets(listdata[i].skill);trim(listdata[i].skill);
    	printf("-Input hobbies:");gets(listdata[i].hobbies);trim(listdata[i].hobbies);
    }
}
int menu()
{
	printf("\n*******************************\n");
	printf("1/Input data for employee\n");
	printf("2/Sort list of member by name\n");
	printf("3/Save data into text file\n");
	printf("4/Print information of employee basing on id\n");
	printf("*******************************\n");
	int check=-1;
	char s[10];
	do
	{
		printf("Your choice:");
		scanf("%s",s);
		check=checknum(s);
	}
	while(check==0);
	int a=convert(s);
	return a;
}
void sort()
{
	struct employee tmp;
	int i,j;
	for(i=1;i<count;i++)
		for (j=i+1;j<=count;j++) if(strcmp(listdata[i].name,listdata[j].name)==1)
			{
				tmp=listdata[i];
				listdata[i]=listdata[j];
				listdata[j]=tmp;
			}
	printf("Sort done!");
}
void save()
{
	FILE*fp=fopen("employee.txt","w");
	int i;
	for (i=1;i<=count;i++)
		{
			fputs(listdata[i].id,fp);
			fputs(" ",fp);
			fputs(listdata[i].name,fp);
			fputs(" ",fp);
			fprintf(fp,"%d",listdata[i].date.day);
			fputs("/",fp);
			fprintf(fp,"%d",listdata[i].date.month);
			fputs("/",fp);
			fprintf(fp,"%d",listdata[i].date.year);
			fputs(" ",fp);
			fputs(listdata[i].skill,fp);
			fputs(" ",fp);
			fputs(listdata[i].hobbies,fp);
			fputs("\n",fp);
		}
	fclose(fp);
	printf("Save done!");
}
void printF()
{
	int i;
	printf("Enter id you want to search: "); getchar();
	char s[100];
	gets(s);trim(s);
	FILE*fp=fopen("employee.txt","r");
	char *tmp[100];
	int flag=0;
	for(i=1;i<=count;i++) tmp[i]=(char*)malloc(100);
	for(i=1;i<=count;i++) fgets(tmp[i],100,fp);
	for(i=1;i<=count;i++)
	{
		char delim[] = " ";
		char n[100];
		strcpy(n,tmp[i]);
		char *ptr = strtok(n,delim);
		if (strcmp(ptr,s)==0) flag=i;
    }
    if (flag!=0) printf("%s",tmp[flag]);
    else printf("Not found!");
    fclose(fp);
    getchar();
}
//void output()
//{
//	int i;
//	for (i=1;i<=count;i++)
//	{ 
//	printf("\n Id: %s",listdata[i].id);
//    printf("\n Name: %s",listdata[i].name);
//    printf("\n Birthday : %d/%d/%d",listdata[i].date.day,listdata[i].date.month,listdata[i].date.year);
//    printf("\n Skill:%s",listdata[i].skill);
//    printf("\n Hobiies:%s",listdata[i].hobbies);
//	}
//}
int main()
{
	int i,choice;
    do
    {
        choice=menu();
        switch (choice)
        {
        case 1: input();
//        		output();
				break;
		case 2: if(count!=0) sort();
				else printf("No data!");
				break;
		case 3: if(count!=0) save();
				else printf("No data!");
				break;
		case 4: if(count!=0) printF();
				else printf("No data!");
				break;
		default: break;
        }
    } while (choice>=1 && choice<=4);
    return 0;
}
