#include<stdio.h>
#include<conio.h>
void main()
{
char x,i,v,j,z;
int m,k;
printf("put the middle alphabate = ");
scanf("%c",&x);
v=x;m=0;z=x;
for(i='A';i<=x;i++)
{
for(j='A';j<=v-1;j++)
printf("%c",j);
for(k=1,j=1;j<m;j++)
{
printf(" ");
while(k!=0)
{
v=v-1;
k--;
}
}
for(j=z;j>='A';j--)
printf("%c",j);
m=m+2;
z=z-1;
printf("\n");
}
getch();
}