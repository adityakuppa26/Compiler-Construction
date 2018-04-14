// the given lex code checks if the given string is an octal number or a hexadecimal number

oct [o|O][0-7]+
hex [o|O][x|X][0-9A-F]+

%%
{oct} { printf("%s is an octal number",yytext);}
{hex} { printf("%s is a hexadecimal number",yytext);}
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
