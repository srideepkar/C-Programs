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

   for(k=0;k<n-1;k++)
   {
     for(i=k+1;i<n;i++)
     {
       r=a[i][k]/a[k][k];
       for(j=0;j<=n;j++)
	   {
	 a[i][j]=a[i][j]-r*a[k][j];
	   }
       }
     }

      x[n-1]=a[n-1][n]/a[n-1][n-1];
      for(j=n-2;j>=0;j--)
      {
       x[j]=a[j][n];
       for(i=n-1;i>j;i--)
	  {
	 x[j]=x[j]-a[j][i]*x[i];
	  }
	 x[j]=x[j]/a[j][j];
       }

	printf("\n The solution is \n");
	for(i=0;i<n;i++)
	   printf(" x[%d]=%.2f \n",i+1,x[i]);
	getch();
  }


