void first(char res[],char c);   // refer first.c
void addres(char r[],char s);    // refer first.c
int main()
{
// similar to the one in first.c
}
void follow(char Result[],char ch)
{
int i,j,k=0,l=0,p=0;
char subResult[20];
subResult[0]='\0';
if(prodset[0][0]==ch)
{
addres(Result,'$');
}
for(i=0;i<np;i++)
{
for(j=2;prodset[i][j]!='\0';j++)
{
if(prodset[i][j]==ch)
{
do
{
p=0;
if(prodset[i][j+1]!='\0')
{
first(subResult,prodset[i][j+1]);
for(k=0;subResult[k]!='\0';k++)
{
if(subResult[k]!='$')
{
addres(Result,subResult[k]);
}
else
{
p=1;
if(prodset[i][j+2]=='\0')
{
follow(Result,prodset[i][0]);
p=0;
}
}
}
strcpy(subResult,"");
}
j++;
}while(p==1);
}
}
}
}
