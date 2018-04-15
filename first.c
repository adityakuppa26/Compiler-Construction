#include<stdio.h>
#include<ctype.h>
char prodset[10][10];
int np;
void first(char [] , char);
void addres(char[] ,char);
int main()
{
int i;
char choice,c;
char result[20];
printf("enter no. of productions:");
scanf("%d",&np);
for(i=0;i<np;i++)
{
printf("\n enter %d production",i+1);
scanf("%s",prodset[i]);
}
do
{
printf("\n find first of :");
scanf("%c",&c);
first(result,c);
printf("\n first of %c is : {",c);
for(i=0;result[i]!='\0'i++)
{
printf("%c",result[i]);
}
printf("}\n");
printf("enter y to continue:");
scanf("%c",&choice);
} while(choice=='y' || choice=='Y');
return 0;
}

void first(char[] Result,char c)
{
int i,j,k,foundEpsilon;
char subResult[20];
if(!isupper(c))
{
addres(Result,c);
return;
}
for(i=0;i<np;i++)
{
if(prodset[i][0]==c)
{
if(prodset[i][2]=='$')
{
addres(Result,'$');
}
else
{
j=2;
while(prodset[i][j]!='\0')
{
foundEpsilon=0;
first(subResult,prodset[i][j]);
for(k=0;subResult[k]!='\0';k++)
addres(Result,subResult[k]);
for(k=0;subResult[k]!='\0';k++)
{
if(subResult[k]=='$')
{
foundEpsilon=1;
break;
}
}
if(!foundEpsilon)
break;
j++;
}
}
}
}
return;
}

void addres(char res[],char ch)
{
int j;
for(j=0;res[j]!='\0';j++)
{
if(res[j]==ch)
return;
}
res[j]=ch;
res[j+1]='\0';
}
