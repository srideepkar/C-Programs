/* Polynomial addition with link-list*/

#include "stdio.h"
#include "conio.h"
#include "malloc.h"
#include "string.h"
#include "process.h"
#define NULL 0
typedef struct polynode
{
 float coeff;
 int exp;
 struct polynode*link;
}polynode;
polynode* getp_node(float,int);
polynode* creatp_node(polynode*);          // declare fuctions...
polynode* poly_add(polynode*,polynode*);
polynode* attach(float,int,polynode*);
void display(polynode*);

void main (void)                           // function main()
{
 polynode *x,*y,*z;                    //declare head(s) as local variable...
 int i=0;
clrscr();

x=y=z=NULL;                          //declare as initially NULL...

printf("\n Enter data to make first polynomial\n\n");
x=creatp_node(x);                                       // creatp_node function calling to create first polynomial...

printf("\n");

printf("\n Enter data to make second polynomial\n\n");
y=creatp_node(y);                                       //  creatp_node function calling to create second polynomial...


clrscr();                                               // use to clear previous writing from the screen...

printf("\n The first polynomial is: \n\n");
printf ("\n\n");
display(x);

printf("\n");

printf("\n The second polynomial is: \n\n");
printf("\n");
display(y);
printf("\n");

printf("\n");
while(i<79)                                            // to creat a horaizental straigth line...
  {
  printf("_");
  i++;
  }
printf ("\n The resultant value after addition of two polynomials is: \n");
printf("\n");
																								 //poly_add function calling...
z=poly_add(x,y);
printf("\n");

display(z);
printf ("\n");
printf("\n Press any key to exit... ... ");
getch();
}

polynode* getp_node(float x,int y)                // to creat a polynode...
{
polynode *new1;
new1=(polynode*)malloc(sizeof(polynode));
new1->link=NULL;
new1->coeff=x;
new1->exp=y;
return(new1);
}

polynode* creatp_node(polynode *head)             // to creat poly list...
{
polynode *ptr,*new1;
float x;
int y;
char a;

printf("\n Enter the coefficient: ");
scanf ("%f",&x);
printf("\n");
printf ("\n Enter the exponent: ");
scanf("%d",&y);

head=getp_node(x,y);
ptr=head;
printf("\n Creat more polynodes (y/n)!!: ");
fflush(stdin);
a=getche();
while(a=='y'||a=='Y')                           // creat poly nodes as dinamically...
 {
  printf("\n Enter the coefficient: ");
  scanf ("%f",&x);
  printf("\n");

  printf ("\n Enter the exponent: ");
  scanf("%d",&y);

  new1=getp_node(x,y);
  new1->coeff=x;
  new1->exp=y;
  ptr->link=new1;
  ptr=new1;
  printf("\n Creat more polynodes (y/n)!!: ");
  fflush(stdin);
  a=getche();
 }
 return(head);
}

void display(polynode *q)                        // to dis play the poly list...
{
 while(q!=NULL)
  {
	printf("%.1fX^%1d + ",q->coeff,q->exp);
	q=q->link;
  }
 printf("\b\b\b");                              //erases the last colon...
}



polynode* poly_add(polynode *a,polynode *b)     // function for polynomial addition... a&b as two amin arguments
{
polynode *p,*q,*c,*d;
float x;
p=a;
q=b;
c=(polynode*)malloc(sizeof(polynode));
d=c;            //initial node for c which is empty...
while(p!=NULL && q!=NULL)                // traverse 1st to last
{
if (p->exp < q->exp)                           // compair the exponent part of 1st poly list with 2nd...
 {
  d=attach(q->coeff,q->exp,d);               // store the term in a new node d
  q=q->link;                    // go to next node..
 }
 else
 {
  if (p->exp > q->exp)                    // compairing...
  {
	d=attach(p->coeff,p->exp,d);           //attach function calling
	p=p->link;                   //go to next node...
  }
  else
  {
	if (p->exp==q->exp)     // add the coeffciants, when exponents are same..
	 {
	  x=p->coeff+q->coeff;
		if (x!=0)
		 {
		  d=attach(x,p->exp,d);
		  p=p->link;
		  q=q->link;
		 }
		 else
		 {
		  exit(0);
		 }
	  }
	}
 }
}

while (p!=NULL)                 //copy rest of 1st pl
 {
  d=attach(p->coeff,p->exp,d);
  p=p->link;
 }

while (q!=NULL)                 //copy rest of 2nd pl
 {
  d=attach(q->coeff,q->exp,d);
  q=q->link;
 }

d->link=NULL;

p=c;                  //erasing imitaed node... p ...
c=c->link;
free(p);
return(c);             // return a poly list with the value of addition  of two given poly list
}

polynode* attach(float item,int expo,polynode *d)  // attach function...
{
 polynode *x;

 x=(polynode*)malloc(sizeof(polynode));
 x->coeff=item;
 x->exp=expo;
 d->link=x;
 d=x;

 return(d);
}


















