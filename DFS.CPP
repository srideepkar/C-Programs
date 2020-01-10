			/* TO PRODUCE D.F.S.-RITOBAN (ok)*/
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<string.h>
#include<process.h>
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

	void push(sn1 *a[],int *top,sn1 **item)
	 {
		if((*top)<MAX)
		 {
			(*top)=(*top)+1;
			a[*top]= (*item);
		 }
		else
		 {
		  printf("   STACK OVERFLOW");
		  exit(0);
		 }
	 }/*End of PUSH funct. */

	void pop(sn1 *a[],int *top,sn1 **item)
	 {
		 if(*top > -1)
		  {
			 *item=a[*top];
			 *top=(*top)-1;
		  }
		 else
			 printf("STACK UNDERFLOW");

	 }/*End of POP funct. */

	void main()
	 {
	  int top=-1,x,z;
	  sn1 *a[20],*h,*ptr,*ptr2;
	  sn2 *ptr1;
	  h=NULL;
	  clrscr();
	  printf("        ---------------WELCOME----------------                        (RITOBAN)\n\n");
	  printf("PLEASE ENTER THE REQD. INFORMATION OF UR GRAPH AS WANTED IN THE FOLL. STEPS\n\n");
	  printf("Enter vertex no.(999 to discontinue):");
	  scanf("%d",&x);
		while(x != 999)
		 {
			add(&h,x);
			printf("Enter vertex no.(999 to discontinue):");
			scanf("%d",&x);
		 }

		ptr=h;
		while(ptr != NULL)
			{
			  printf("ENTER THE VERTEX (if any) ADJACENT TO %d (else enter 0):",ptr->info);
			  scanf("%d",&z);
				  if(z != 0)
					  adj1(z,&ptr,&h);
				  else
					  ptr=ptr->next;
			}
		display(&h);


		printf("\nENTER THE VERTEX FROM WHICH U WANT TO START:");
		scanf("%d",&x);
		ptr=h;
		while(ptr != NULL)
		 {
			if(ptr->info==x)
			  {
					ptr->status=2;
					push(a,&top,&ptr);
					break;
			  }
			else
				ptr=ptr->next;
		 }

		while(1)
		{
			pop(a,&top,&ptr);
			ptr->status=3;
			printf("%d  ",ptr->info);
			ptr1=ptr->adj;

				while(ptr1!=NULL)
				 {
					 if(ptr1->vertex->status==1)
						{
						  ptr1->vertex->status=2;
						  ptr2=ptr1->vertex;
						  push(a,&top,&ptr2);
						}
					 ptr1=ptr1->next1;
				 }

			if(top == -1)
			  break;
		} /*END OF while LOOP */

	 getch();

 } /* END OF main */