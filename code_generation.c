#include<stdio.h>
char stk[100],stktop=-1,cnt=0;

void push(char c)
{
stk[++stktop]=c;
}

char pop()
{
return stk[stktop--];
}

char checkoperation(char oper)
{
char op;
if(oper=='+')
op='A';
else if(oper=='-')
op='S';
else if(oper=='*')
op='M';
else if(oper=='/')
op='D';
else if(oper=='@')
op='N';
return op;
}

int checknstore(char check)
{
inr ret;
if(check!='+'&& check!='-' && check!='*' && check!='/' && check!='@')
push(++cnt);
if(stktop>0)
{
printf("ST \n %d ",cnt);
ret=1;
}
else
{
ret=0;
}
return ret;
}

int main()
{
char msg[100],op1,op2,operation;
int i,val;
while(scanf("%s",msg)!=EOF)
{
cnt=0;
stktop=-1;
for(i=0;msg[i]!='\0';i++)
{
if((msg[i]>='A'&&msg[i]<='Z')||(msg[i]>='a' && msg[i]<='z'))
push(msg[i]);
else
{
op1=pop();
op2=pop();
printf("L %c",op2);
operation=checkoperation(msg[i]);
printf("%c %c ",operation,op1);
val=checknstore(msg[i+1]);
while(val==0)
{
op1=pop();
cnt--;
operation=checkoperation(msg[++i]);
if(opeation=='S' && stktop>=-1)
{
printf("N \n");
operation='A';
}
printf("%c %c",operation,op1);
val=checknstore(msg[i+1]);
}
}
}
}
}
