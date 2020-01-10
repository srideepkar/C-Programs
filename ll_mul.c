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
polynode* creatp_node(polynode*);
polynode* poly_add(polynode*,polynode*);
polynode* attach(float,int,polynode*);
polynode* poly_mul(polynode*,polynode*);
void display(polynode*);

void main (void)
{
 polynode *x,*y,*z;
 int i=0;
clrscr();

x=y=z=NULL;

printf("\n Enter data to make first polynomial\n\n");
x=creatp_node(x);

printf ("\n");

printf("\n Enter data to make second polynomial\n\n");
y=creatp_node(y);

printf("\n");

clrscr();
printf("\n The first polynomial is: \n\n");
printf ("\n\n");
display(x);
printf("\n");
printf("\n The second polynomial is: \n\n");
printf("\n\n");
display(y);
printf("\n");

printf("\n");

while(i<79)
  {
  printf("_");
  i++;
  }
printf ("\n The resultant value after multiplication of two polynomiais is:> \n");
printf("\n");

z=poly_mul(x,y);
display(z);
printf ("\n");
printf("\n Press any key to exit... ... ");
getch();
}

polynode* getp_node(float x,int y)
{
polynode *new1;
new1=(polynode*)malloc(sizeof(polynode));
new1->link=NULL;
new1->coeff=x;
new1->exp=y;
return(new1);
}

polynode* creatp_node(polynode *head)
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
while(a=='y'||a=='Y')
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

void display(polynode *q)
{
 while(q!=NULL)
  {
	printf("%1fX^%1d + ",q->coeff,q->exp);
	q=q->link;
  }
 printf("\b\b\b");
}



polynode* poly_add(polynode *a,polynode *b)
{
polynode *p,*q,*c,*d;
float x;
p=a;
q=b;
c=(polynode*)malloc(sizeof(polynode));
d=c;
while(p!=NULL && q!=NULL)
{
if (p->exp < q->exp)
 {
  d=attach(q->coeff,q->exp,d);
  q=q->link;
 }
 else
 {
  if (p->exp > q->exp)
  {
	d=attach(p->coeff,p->exp,d);
	p=p->link;
  }
  else
  {
	if (p->exp==q->exp)
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

while (p!=NULL)
 {
  d=attach(p->coeff,p->exp,d);
  p=p->link;
 }

while (q!=NULL)
 {
  d=attach(q->coeff,q->exp,d);
  q=q->link;
 }

d->link=NULL;

p=c;
c=c->link;
free(p);
return(c);
}

polynode* attach(float item,int expo,polynode *d)
{
 polynode *x;

 x=(polynode*)malloc(sizeof(polynode));
 x->coeff=item;
 x->exp=expo;
 d->link=x;
 d=x;

 return(d);
}


polynode* poly_mul(polynode *a,polynode *b)
{
polynode *g,*f,*d,*m,*n,*i;
float l;
int k;

n=b;
g=NULL;

while(n!=NULL)
{
 m=a;

  f=(polynode*)malloc(sizeof(polynode));
  d=f;

while(m!=NULL)
 {
  l=(m->coeff*n->coeff);
  k=(m->exp+n->exp);
  d=attach(l,k,d);
  m=m->link;
 }

 d->link=NULL;
 i=f;
 f=f->link;
 free(i);

 g=poly_add(g,f);
 n=n->link;
 }
 return(g);
}


















