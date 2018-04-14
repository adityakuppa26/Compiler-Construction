// recursive descent parser implementation for the below grammar :

// E -> TE'
// E' -> +TE' | ε
// T -> FT'
// T' -> *FT' | ε
// F -> (E) | id

#include<stdio.h>
#include<ctype.h>
#include<string.h>
char a[10];
int i;
void t();
void eprime();
void f();
void tprime();
void e();
int main()
{
i=0;
printf("enter the string:");
scanf("%s",&a);
e();
if(strlen(a)==i)
printf("\n string accepted \n");
else
printf("string not accepted \n" );
return 0;
}

void e()
{
t();
eprime();
}

void eprime()
{
if(a[i]=='+')
{
i++;
t();
eprime();
}
}

void t()
{
f();
tprime();
}

void tprime()
{
if(a[i]=='*')
{
i++;
f();
tprime();
}
}

void f()
{
if(isalnum(a[i]))
{
i++;
}
else if
{
if(a[i]=='(')
i++;
e();
if(a[i]==')');
i++;
}
}
