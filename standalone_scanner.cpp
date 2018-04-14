#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
using namespace std;

int iskeyword(char buffer[])       // checks if buffer[] is a keyword
{
char keywords[32][10]={
 "auto",     "break",    "case",     "char",     "const",     "continue",
 "default",    "do",       "double",   "else",     "enum",      "extern",
 "float",      "for",      "goto",     "if",       "int",       "long",
 "register",   "return",   "short",    "signed",   "sizeof",    "static",
 "struct",     "switch",   "typedef",  "union",    "unsigned",  "void",
 "volatile",   "while"}
 int i,flag=0;
 for(i=0;i<32;i++)
 {
 if(strcmp(buffer,keywords[i])==0)
 {
 flag=1;
 break;
 }
 }
 return flag;                   // returns 1 if keyword else 0
}

int main()
{
char operators[6]="+-/*%=";
char buffer[10];
int i,j=0;
fstream fin("program.txt");
if(!fin.is_open())
{
cout<<"error opening file";
exit(-1);
}
char ch;
while(fin)
{
ch=fin.get();
for(i=0;i<6;i++)
{
if(ch==operators[i])
{
cout<<ch<<" is an operator";
}
}
if(isalnum(ch))
{
buffer[j++]=ch;
}
else if((ch==' '|| ch=='\n') && (j!=0))
{
buffer[j]='\0';
j=0;
if(iskeyword(buffer)==1)
{
cout<<buffer<<" is a keyword";
}
else
cout<<buffer<<" is an identifier";
}
}
fin.close();
return 0;
}
