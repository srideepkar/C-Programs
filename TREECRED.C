#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

typedef struct btree
{
int data;
struct btree *left,*right;
}btree;

btree *root;

btree *getnode(char x)
{
btree *p;
p=(btree*)malloc(sizeof(btree));
p->data=x;
p->left=NULL;
p->right=NULL;
return(p);
}

void createbtree()
{
btree *p,* QUEUE[50];
char x;
int front=0,rear=0;
printf("Enter the root element ");
scanf("%c",&x);
root=getnode(x);
QUEUE[rear]=root;
while (front<=rear)
{
p=QUEUE[front++];
printf("Enter left element of %c(enter for none) ",p->data);
fflush(stdin);
scanf("%c",&x);
if(x != '\n')
{
p->left=getnode(x);
QUEUE[++rear]=p->left;
}
printf("Enter right element of %c(enter for none) ",p->data);
fflush(stdin);
scanf("%c",&x);
if(x != '\n')
{
p->right=getnode(x);
QUEUE[++rear]=p->right;
}
}
}

void displaybtree()
{
btree *p,*ptr,*QUEUE[50];
int front=0,rear=0;
if(root==NULL)
{
printf("Tree not exist.....");
getch();
return;
}
QUEUE[rear]=root;
while(front<=rear)
{
 p=QUEUE[front++];
 printf("%c ",p->data);
 if(p->left!=NULL)
     QUEUE[++rear]=p->left;
if(p->right!=NULL)
     QUEUE[++rear]=ptr->right;
}
}

void main()
 {
 clrscr();
 createbtree();
 printf("\n\n Tree after traversal is.......\n\n");
 displaybtree();
 getch();
 }
