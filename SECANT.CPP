#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x){
	return (x*x-9.0*x+2.0);
}

void main()
{
	int iteration=0,flag,sign=-1;
	float a,b,x,y,h;
	clrscr();
	printf("\t\t\tSECANT METHOD\n");
	printf("\t\t\t-------------\n\n");
	x=0.0;
	do{
		y=f(x);
		if(y>0.0)
			a=x;
		else
			b=x;
		x*=sign;
		if(x>=0)
			x++;
	}while(f(a)*f(b)>=0);
	printf("x0=%f\tf(x0)=%f\n\n",a,f(a));
	printf("n  xn\t\tf(xn)\t\th=-(((xn-x0)*f(x0))/f(xn)-f(x0))   x(n+1)=x0+h\n");
	do{
		flag=0;
		iteration++;
		h=-((b-a)*f(a)/(f(b)-f(a)));
		x=a+h;
		if(fabs(x-b)>.0005){
			flag=1;
			printf("%d  %f\t%f\t%f\t\t\t   %f\n",iteration,b,f(b),h,x);
			b=x;
		}
	}while(flag);
	printf("\nThe final result is:%f",b);
	getch();
}