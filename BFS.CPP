			/* BREADTH FIRST SEARCH OK */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<alloc.h>
#define MAX 10


	struct node1;

	typedef struct node2
	  {
		 struct node1 *vertex;
		 struct node2 *next1;
	  }sn2;

	typedef struct node1
	  {
		 int status;
		 int info;
		 struct node1 *next;
		 struct node2 *adj;
	  }sn1;

	void add(sn1 **h,int x)
	 {
		sn1 *new1,*ptr;
		new1=(sn1 *)malloc(sizeof(sn1));
		new1->status=1;
		new1->info=x;
		new1->next=NULL;
		new1->adj=NULL;

		  if(*h==NULL)
			*h=new1;
		  else
			{
			  ptr=*h;
				 while(ptr->next != NULL)
					ptr=ptr->next;
			  ptr->next=new1;
			}
	 } /*END OF function */

     /*  please give comment lines z=,  ptr=, h= */

	void adj1(int z,sn1 **ptr,sn1 **h)
	     {
		sn1 *ptr1;
		sn2 *new1,*ptr2;

		ptr1=*h;
		while(ptr1->info != z && ptr1->next != NULL)
			  ptr1=ptr1->next;

		/* create node of adjacent nodes */

		new1=(sn2 *)malloc(sizeof(sn2));
		new1->vertex=ptr1;
		new1->next1=NULL;
		  if((*ptr)->adj==NULL)
			(*ptr)->adj=new1;
		  else
			{
			ptr2=(*ptr)->adj;
				while(ptr2->next1 != NULL)
					ptr2=ptr2->next1;
				ptr2->next1=new1;
			}
	    } /*END OF function */

	void display(sn1 **h)
	  {
		 sn1 *ptr;
		 sn2 *ptr1;
		 ptr=*h;
		 while(ptr != NULL)
			{
			 printf("\n %d :",ptr->info);
			 ptr1=ptr->adj;
			 while(ptr1 !=NULL)
				{
				 printf("%d  ",ptr1->vertex->info);
				 ptr1=ptr1->next1;
				}
			 ptr=ptr->next;
		  }
	  } /*END OF function */

	void qinsert(sn1 *a[],int *front,int *rear,sn1 **item)
	 {
		if(*front==-1)
		  *front=*front+1;
		if(*rear<MAX-1)
		 {
			*rear=*rear+1;
			a[(*rear)]=(*item);
		 }
		else
		 {
		  printf("\n QUEUE IS FULL.....\n");
		  exit(0);
		 }
	 }/*End of QINSERT funct. */

	void qdelete(sn1 *a[],int *front,int *rear,sn1 **item)
	 {
		 if(*front==-1)
			 printf("\n QUEUE IS EMPTY..... \n ");
		 else
		  {
			 if(*front==*rear)
				{
					*item=a[*front];
					*front=*rear=-1;
				}
			 else
				{
					*item=a[*front];
					*front=*front+1;
	    }
		  }
	 }/*End of QDELETE funct. */

	void main()
	 {
	  int front=-1,rear=-1,x,z;
	  sn1 *a[10],*h,*ptr,*ptr2;
	  sn2 *ptr1;
	  clrscr();
	  printf("        ---------------WELCOME----------------                        (RITOBAN)\n\n");
	  printf("PLEASE ENTER THE REQD. INFORMATION OF UR GRAPH AS WANTED IN THE FOLL. STEPS\n\n");
	  printf("Enter vertex no.(999 to discontinue): ");
	  scanf("%d",&x);
	  h=NULL;
		while(x != 999)
		 {
			add(&h,x);
			printf("\n Enter vertex no.(999 to discontinue): ");
			scanf("%d",&x);
		 }

		ptr=h;
		while(ptr != NULL)
			{
			  printf("\n Enter the vertex (if any) adjacent to %d (else enter 0): ",ptr->info);
			  scanf("%d",&z);
				  if(z != 0)
					  adj1(z,&ptr,&h);
				  else
					  ptr=ptr->next;
			}
			display(&h);
		printf("\n Enter the vertex from which you want to start: ");
		scanf("%d",&x);
		ptr=h;
		while(ptr != NULL)
		 {
			if(ptr->info==x)
			  {
					ptr->status=2;
					qinsert(a,&front,&rear,&ptr);
					break;
			  }
			else
				ptr=ptr->next;
		 }

		while(1)
		{
			qdelete(a,&front,&rear,&ptr);
			ptr->status=3;
			printf("%d  ",ptr->info);
			ptr1=ptr->adj;

				while(ptr1!=NULL)
				 {
					 if(ptr1->vertex->status==1)
						{
						  ptr1->vertex->status=2;
						  ptr2=ptr1->vertex;
						  qinsert(a,&front,&rear,&ptr2);
						}
					 ptr1=ptr1->next1;
				 }
			if(front==-1)
			  break;
		} /*END OF while LOOP */
	     getch();
 }
