/*  friend Template function  */

#include "iostream.h"
#include "conio.h"

template <class T>
class std2;

template<class T>
class std1
{
   private:
	T x1,x2;
   public:
/* constructor */
	std1()
	    {
		x1=0.0;
		x2=0.0;
	    }
	void getdata()
	   {
		cout<<"Enter the values:  ";
		cin>>x1>>x2;
	   }
	void display()
	{
	cout<<"After addition result is....\n"<<x1<<"\n"<< x2;
	}
       friend std1<T> ff(std1<T> a,std2<T> b);
};

template<class T>
class std2
{
   private:
	T y1,y2;
public:
/* constructor */
	std2()
	   {
		y1=0.0;
		y2=0.0;
	   }
	void getdata()
	   {
		cout<<"Enter the values:  ";
		cin>>y1>>y2;
	   }
 friend std1<T> ff(std1<T> a,std2<T> b);
};

 template<class T>
std1<T> ff(std1<T> obj1,std2<T> obj2)
{
obj1.x1=obj1.x1 + obj2.y1;
obj1.x2=obj1.x2 + obj2.y2;
return(obj1);
}

void main()
{
clrscr();
std1<float> m1;
std2<float> m2;
m1.getdata();
m2.getdata();
m1=ff(m1,m2);
m1.display();
getch();
}