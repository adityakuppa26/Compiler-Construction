identifier [a-zA-Z]+[0-9]*[a-zA-Z]*

%%
 auto|break|case|char|const|continue|
 default|do|double|else|enum|extern|
 float|for|goto|if|int|long|
 register|return|short|signed|sizeof|static|
 struct|switch|typedef|union|unsigned|void|
 volatile|while {printf("%s is a keyword",yytext);}
 
 {identifier} {printf("%s is an identifier",yytext);}
 
 "+"|"-"|"*"|"/"|"%"|"="|"^"|"!"|">"|"&&"|"<"|"==" { printf("%s is an operator",yytext);}
 
 ")"|"\\"|")"|"{"|"}"|"["|"]" {printf("%s is a metacharacter",yytext);}
 
 #.* {printf("%s is a preprocessor directive",yytext);}
 
 %%
 
 int main(int argc,char** argv)
 {
 if(argc>1)
 {
 yyin=fopen(argv[1],"r");
 }
 else
 {
 yyin=stdin;
 }
 yylex();
 return 0;
 }
 int yywrap()
 {
 return 1;
 }
