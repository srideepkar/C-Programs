/* 		         surya rules			*/

/*	    simpson's 1/3 rule & trapezoidal rule	*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"
#include"math.h"
#include"alloc.h"
#include"ctype.h"


float f(float x)
{
	return x/(1+x);;
}

void main()
{

	float lower,upper,h,sum=0;
	float Y[20],X[20];
	int interval,i;

	clrscr();

	printf("enter the lower limit: ");
	scanf("%f",&lower);
	printf("enter the upper limit: ");
	scanf("%f",&upper);
	printf("enter the no. of sub intervals: ");
	scanf("%d",&interval);

	h=(upper-lower)/interval;
	X[0]=lower;

	for(i=0;i<=interval;i++)
	{
		X[i]=X[0]+i*h;
		Y[i]=f(X[i]);

	}

	sum=Y[0]+Y[interval];

	/* simpson's 1/3 rule */

	for(i=1;i<interval;i++)
	{
		if(i%2!=0)
			sum=sum+4*Y[i];
		else
			sum=sum+2*Y[i];
	}

	sum=sum*h/3;

	printf("\n the required answer by simpson's 1/3 rule is: %f",sum);


	/* trapezoidal rule */


	sum=Y[0]+Y[interval];

	for(i=1;i<interval;i++)
	{
		sum=sum+2*Y[i];
	}

	sum=sum*h/2;

	printf("\n\n the required answer by trapezoidal rule is: %f",sum);

	getch();

}


