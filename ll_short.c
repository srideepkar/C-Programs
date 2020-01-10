#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "malloc.h"
#define NULL 0
typedef struct node
{
 int data;
 struct node *link;
}node;
node* getnode(int);
void create_list(void);
void b_short(void);
void displaylist(void);
node *head;
void main(void)
{
 int f=0,count=0,ch,flag=1;
 fflush(stdin);
 clrscr();
 do
 {
  clrscr();
  do
  {
	clrscr();
	flag=1;
	printf("\n\n\n\n                       ****----    MENU    ----****");
	printf("\n\nTo create a linked list --> Press 1..");
	printf("\n\nTo shorting the list in sequencial order -->Press 2..");
	printf("\n\nTo display the linked list-->Press 3..");
	printf("\n\nTo exit -->Press 4..");
	printf("\n\n\nNow enter your choice: ");
	scanf("%d",&ch);             //choice entering..
	if(ch<=4&&ch>=1)
	  flag=0;
  }while(flag==1);
  switch(ch)
  {
	case 1:
	 count++;
	 if(count!=1)
	 {
	  printf("\nlist is already created.. please enter correct choice..");
	  break;
	 }
	 create_list();
	 f=0;
	 break;
	 case 2:
	 if(count==0)
	 {
		printf("\n\nnode should be created before sorting!!!");
	   break;
	 }
	 else
	 {
	  b_short();
	  break;
	 }
	 f=0;

	 case 3:
	 displaylist();
	 f=0;
	 getch();
	 break;
	case 4:
	 f=1;
	 break;
  }
 }while(f!=1);
 printf("\n\nPress any key to exit... ... ");
 getch();
}


node* getnode(int x)                      //to create a new node
{
 node *new1;
 new1=(node*)malloc(sizeof(node));
 new1->link=NULL;
 new1->data=x;
 return(new1);
}


void create_list(void)                   //to create a linked list
{
 node *ptr,*new1;
 int x;
 char a;
 printf("\n\nenter the value for the new node: ");
 scanf("%d",&x);
 head=getnode(x);
 ptr=head;
 printf("\nwant to continue again?(y/n): ");
 fflush(stdin);
 a=getche();
 while(a=='y'||a=='Y')
 {
  printf("\n\nenter the value for new the node: ");
  scanf("%d",&x);
  new1=getnode(x);
  new1->data=x;
  ptr->link=new1;
  ptr=new1;
  printf("\n\nwant to continue again?(y/n): ");
  fflush(stdin);
  a=getche();
 }
}


void displaylist(void)                 //to display the present linked list..
{
 node *ptr;
 fflush(stdin);
 ptr=head;
 printf("\n\nYour entered values in the linked list is: ");
 while(ptr!=NULL)
 {
  printf("%d -> ",ptr->data);
  ptr=ptr->link;
 }
 printf(" NULL.");
}


void b_short(void)                     // fuction to short the list...
{
 node *p,*q,*r,*s,*temp;
 s=NULL;

 while(s!=head->link)
  {
	r=p=head;
	q=p->link;

	 while(p!=s)
	 {
	  if (p->data > q->data)
		{
		 if(p==head)
		  {
			 temp=q->link;
			 q->link=p;
			 p->link=temp;

			 head=q;
			 r=q;
		  }
		  else
		  {
			 temp=q->link;
			 q->link=p;
			 p->link=temp;

			 r->link=q;
			 r=q;
		  }
		}
		else
		{
		  r=p;
		  p=p->link;
		}
		q=p->link;
		if(q==s)
			s=p;
	 }
  }
}

