



#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct nodev;

typedef struct Node{
				char ver/*name of the vertex*/;
				struct Node *next/*point to the next vertex*/;
				struct nodev *adj/*point to the adjacency vertex*/;
			}node;

typedef struct nodev{
				node *cv/*point to the corresponding vertex*/;
				struct nodev *add/*address of the next cv*/;
			}edge;

node *getnode();
edge *vertex(int y,node ***h);
void add_vertex(node **h);

int menu();

void main()
{
	int ch;
	node *new1,*h,*ptr1,*ptr;
	edge *ptr2;
	clrscr();
	h=NULL;
	do{
		ch=menu();
		switch(ch){
			case 1:
				new1=getnode();
				if(h==NULL)
					h=new1;
				else{
					ptr1=h;
					while(ptr1->next != NULL)
						ptr1=ptr1->next;
					ptr1->next=new1;
				}
				break;
			case 2:
				add_vertex(&h);
				break;
			case 3:
				ptr1=h;
				while(ptr1 != NULL){
					printf("\n%c:",ptr1->ver);
					ptr=h;
					if(ptr->adj != NULL){
						printf("%c  ",ptr->adj->cv->ver);
						ptr=ptr->adj;
						ptr2=ptr;
						while(ptr2->add != NULL){
							printf("%c",ptr2->cv->ver);
							ptr2=ptr2->add;
						}
					}
					printf("\n");
					ptr1=ptr1->next;
				}
				break;
			case 4:
				exit(0);
			default:
				printf("\nPRESS THE WRITE KEY");
		}
	}while(1);
}

int menu(){
	int x;
	printf("\nMENU____________________________CODE");
	printf("\nVERTEX__________________________1");
	printf("\nCORRESPONDING VERTICES__________2");
	printf("\nDISPLAY_________________________3");
	printf("\nEXIT____________________________4");
	printf("\nChoose a option:");
	scanf("%d",&x);
	return x;
}


node *getnode(){
	int ch;
	node *new1;
	printf("Enter the name of the vertex:");
	fflush(stdin);
	scanf("%c",&ch);
	new1=(node *)malloc(sizeof(node));
	new1->ver=ch;
	new1->next=NULL;
	new1->adj=NULL;
	return new1;
}

edge *vertex(int y,node ***h){
	node *ptr;
	edge *new2;
	ptr=**h;
	while(ptr->ver != y && ptr->next != NULL)
		ptr=ptr->next;
	if(ptr->ver == y){
                new2=(edge *)malloc(sizeof(edge));
		new2->cv=ptr;
		new2->add=NULL;
		free(ptr);
		return new2;
	}
	else{
		printf("\nThe vertex you are chosen not found");
		getch();
		exit(0);	
	}	
}

void add_vertex(node **h){
	node *ptr1,*ptr;
	edge *ptr2,*new2;
	char x,y;
	printf("\nEnter the name of the main vertex:");
	fflush(stdin);
	scanf("%c",&x);
	ptr1=*h;
	while(ptr1->ver != x && ptr1->next != NULL)
		ptr1=ptr1->next;
	if(ptr1->ver == x){
		do{
			printf("Enter the name of the vertex you want to join with %c(z to exit):",x);
			fflush(stdin);
			scanf("%c",y);
printf("\n   %c\n",y);
			if(y !='z'){
				new2=vertex(y,h);
				ptr=ptr1;
				if(ptr->adj == NULL){
					ptr->adj = new2;

				}
				else{
					ptr2=ptr;
					while(ptr2->add != NULL)
						ptr2=ptr2->add;						
					ptr2=new2;
				}
			}
		}while(y != 'z');
		return;
	}
	else{
		printf("\nThe main vertex is not found");
		getch();
		return;
	}
}