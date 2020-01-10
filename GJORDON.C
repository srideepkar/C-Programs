/* Gauss elimination method */
#include<stdio.h>
#include<conio.h>

void main()
{
 int i,j,k,n;
 float a[20][20],x[20],r;
 clrscr();
 printf(" Enter the no. of equations: ");
 scanf("%d",&n);
 printf("\n Enter co-efficient matrix R.H.S row wise: ");
 for(i=0;i<n;i++)
  {
   for(j=0;j<=n;j++)
   {
     printf("\n a[%d][%d]= ",i,j);
     scanf("%f",&a[i][j]);
    }
   }

   for(k=0;k<n;k++)
   {
     for(i=0;i<n;i++)
     {
       if(i==k) continue;
       r=a[i][k]/a[k][k];
       for(j=0;j<=n;j++)
	   {
	 a[i][j]=a[i][j]-r*a[k][j];
	   }
       }
     }
     for(i=0;i<n;i++)
     {
       for(j=0;j<=n;j++)
	 printf("%.2f  ",a[i][j]);
       printf("\n");
     }

	printf("\n The solution is \n");
	for(i=0;i<n;i++)
	   printf(" x[%d]=%.2f \n",i+1,a[i][n]/a[i][i]);
	getch();
  }


