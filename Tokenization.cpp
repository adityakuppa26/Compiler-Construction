#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ifstream fin("program.txt");    // program.txt contains the sample program for conducting tokenization
if(!fin.is_open())
{
cout<<"error opeing file";
exit(-1);
}
int line=1,word=1,size;
char ch;
fin.seekg(0,ios:end);
size=fin.tellg();
fin.seekg(0.ios:beg);
while(fin)
{
fin.get(ch);
if(ch==" " || ch=="n")
{
word++;
}
else if(ch=="n")
{
line++;
}
}
cout<<"size="<<size<<"lines="<<line<<"words="<<word;
return 0;
}
