// to find complete real precision number

integer [0-9]+
floating ([0-9]+\.[0-9]+)|([+|-]?[0-9]+\.[0-9]+[e|E][+|-][0-9]+)

%%

{integer} {printf("%s is an integer",yytext);}
{floating} {printf("%s is a floating number",yytext);

%%

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
