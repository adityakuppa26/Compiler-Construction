#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int i,j,k,p,n,l,m,flag=0;
char c[3][10],b[10][10];
printf("enter the productions(max=3)");
for(i=0;i<3;i++)
{
    scanf("%s",&c[i]);
}
l=0;m=0;
for(i=0;i<3;i++)
{
    p=1;
    for(j=0;j<strlen(c[i]);j++)
    {
        for(k=0;k<strlen(c[i]);k++)
        {
            if(k==p)
            {
                b[l][m]='.';
                m++;
                b[l][m]=c[i][k];
                m++;
            }
            else
            {
            b[l][m]=c[i][k];
            m++;
            }
        }
       l++;m=0;p++;
    }
}
for(i=0;i<l;i++)
{
        flag=0;
        for(k=0;k<strlen(b[i]);k++)
        {
            if(b[i][k]=='.')
            {
                flag=1;
            }
        }
        if(flag==0)
        {
           b[i][strlen(b[i])]='.';
        }
}
printf("the states are:\n");
for(i=0;i<l;i++)
    printf("%d\t%s\n",i+1,b[i]);
}
