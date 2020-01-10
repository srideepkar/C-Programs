#include "stdio.h"
#include "conio.h"
#include "malloc.h"
#include "string.h"
#include "process.h"
#define NULL 0
typedef struct node
{
  int data;
  struct node *link;
}node;
node* getnode(int);
void create_list(void);
void reverse(void);
void displaylist(void);
node *head;                 // define head pointer as global veriable...
void main (void)
{
clrscr();
printf ("\n Enter the data for the link list. ");
printf ("\n\n");

create_list();                              // create_list function calling...
printf ("\n The entered link list is: \n");
printf("\n");
displaylist();                              // display function calling...

printf("\n");
														  //reverse function calling...
reverse();
printf ("\n The link list after reversing: \n");
displaylist();
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
 while(a=='y'||a=='Y')                    // creat the list as dina mical way...
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
 printf("\n\n the corrent linked list is: ");
 while(ptr!=NULL)
 {
  printf("%d -> ",ptr->data);
  ptr=ptr->link;
 }
 printf(" NULL.");
}

void reverse(void)                      // To reverce the list...
{
 node *q,*r,*s;

 q=head;
 r=NULL;

while(q!=NULL) // traverce the entire list
{
 s=r;
 r=q;
 q=q->link;
 r->link=s;
}
head=r;
}


