// capitalizes a given string

%{ 
#include<stdio.h>
#include<ctype.h>
void display(char*);
%}

str [a-zA-Z]+

%%

{str} {display(yytext);}

%%

void display(char* s)
{
int i;
for(i=0;s[i]!='\0';i++)
{
printf("%c",toupper(s[i]));
}
}

int main()
{
yyin=stdin;
yylex();
return 0;
}

int yywrap()
{
return 1;
}
