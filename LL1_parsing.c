#include<stdio.h>
#include<conio.h>
#include<string.h>
char s[20],stk[20];
void main()
{
int i,j,k,n,str1,str2;
char m[5][6][3]={"tb"," "," ","tb"," "," "," ","+tb"," "," ","n","n","fc"," "," ","fc"," "," "," ","n","*fc","a","n","n","i"," "," ","(e)"," "," "};
int size[5][6]={2,0,0,2,0,0,0,3,0,0,1,1,2,0,0,2,0,0,0,1,3,0,1,1,1,0,0,3,0,0};
printf("enter the input");
scanf("%s",s);
strcat(s,"$");
n=strlen(s);
stk[0]='$';
stk[1]='e';
i=1;
j=0;
while(stk[i]!='$' && s[j]!='$')
{
if(stk[i]==s[j])
{
i--;
j++;
}
switch(stk[i])
{
case 'e' : str1=0;
break;
case 'b': str1=1;
break;
case 't' : str1=2;
break;
case 'c': str1=3;
break;
case 'f' : str1=4;
break;
}
switch(s[j])
{
case 'i' : str2=0;
break;
case '+' : str2=1;
break;
case '*' : str2=2;
break;
case '(' : str2=3;
break;
case ')' : str2=4;
break;
case '$' : str2=5;
break;
}
if(m[str1][str2][0]=='\0')
{
printf("\n error");
exit(-1);
}
else if(m[str1][str2][0]=='n')
i--;
else if(m[str1][str2][0]=='i')
{
stk[i]='i';
}
else
{
for(k=size[str1][str2]-1;k>=0;k--)
{
stk[i]=m[str1][str2][k];
i++;
}
i--;
}
for(k=0;k<=i;k++)
{
printf("%c",stk[k]);
}
printf(" ");
for(k=j;k<=n;k++)
{
printf("%c",s[k]);
}
printf("\n");
}
printf("Success");
}
