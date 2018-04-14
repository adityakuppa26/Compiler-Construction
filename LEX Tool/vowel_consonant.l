// checks if the given character is a vowel or a consonant

%{
#include<stdio.h>
void display();
int flag=0;
%}

vow [a|e|i|o|u|A|E|I|O|U]

%%

{vow} { flag=1; display();}

%%

void display()
{
if ( flag==1)
{
printf(" %s is a vowel",yytext);
}
else
printf("%s is a consonant",yytext);
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
