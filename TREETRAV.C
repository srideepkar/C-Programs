#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0
#include<process.h>

typedef struct btree
{
int data;
struct btree *left,*right;
}btree;

btree *root;
btree *getnode(char x);
void createbtree();
void displaybtree();
void preorder(btree*root);
void inorder(btree*root);
void postorder(btree*root);
void main()
{
int ch;
do
{
clrscr();
printf("1.create btree\n2.display btree\n3.preorder traversal\n4.inorder traversal\n5.postorder traversal\n6.Exit\nEnter your choice...");
scanf("%d",&ch);
switch(ch)
{
case 1:
 createbtree();
break;
case 2:
  displaybtree();
  getch();
  break;
case 3:
preorder(root);
getch();
break;
case 4:
inorder(root);
getch();
break;
case 5:
postorder(root);
getch();
break;
case 6:
  exit(0);
default:
	printf("wrong key pressing");
	}
   } while(1);
}   //end of main
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
btree *p,*ptr,*QUEUE[50];
char x;
int front=0,rear=0;
printf("Enter the root element ");
fflush(stdin);
scanf("%c",&x);
root=getnode(x);
QUEUE[rear]=root;
while(front<=rear)
{
p=QUEUE[front++];
printf("enter left element of %c(enter for none)",p->data);
fflush(stdin);
scanf("%c",&x);
if(x!='\n')
{
p->left=getnode(x);
QUEUE[++rear]=p->left;
}
printf("enter right element of %c(enter for none)",p->data);
fflush(stdin);
scanf("%c",&x);
if(x!='\n')
{
p->right=getnode(x);
QUEUE[++rear]=p->right;
}
}
}

void displaybtree()
{
btree *p,*QUEUE[50];
int front=0,rear=0;
if(root==NULL)
{
printf("tree not exist");
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
QUEUE[++rear]=p->right;
}
getch();
}

void preorder(btree*root)
{
btree *STACK[50],*ptr;
int top=-1;
if(root==NULL)
{
printf("tree not exist");
getch();
return;
}
ptr=root;
do{
while(ptr!=NULL)
{
printf("%c ",ptr->data);
if(ptr->right!=NULL)
STACK[++top]=ptr->right;
ptr=ptr->left;
}
if(top==-1)
break;
ptr=STACK[top--];
}while(1);
}
void inorder(btree*root)
{
btree *STACK[50],*ptr;
int top=-1;
ptr=root;
do{
while(ptr!=NULL)
{
STACK[++top]=ptr;
ptr=ptr->left;
}
if(top==-1)
break;
ptr=STACK[top--];
printf("%c ",ptr->data);
ptr=ptr->right;
}while(1);
}
struct STACK
{
btree *add;
int index;
}STACK;

void postorder(btree *root)
{
struct STACK
{
btree *add;
int index;
} a[50];

btree *p;
int top=-1;
if(root==NULL)
{
printf("Tree not exist....");
return;
}
p=root;
do{
while(p!=NULL)
{
top++;
a[top].add=p;
a[top].index=0;
p=p->left;
}
while(top != -1 && a[top].index==1)
{
p=a[top].add;
top=top-1;
printf("%c ",p->data);
}
if(top==-1)
break;
a[top].index=1;
p=(a[top].add)->right;
}while(1);
}

