
			/*FLOYD'S ALGORITHM-RITOBAN */

#include<stdio.h>
#include<conio.h>

void main()
 {
	int d[10][10],n,s,i,k,j;
	clrscr();

	/* INPUT PART */

	printf("Enter the order of the matrix:");
	scanf("%d",&n);
	printf("Enter the matrix row-wise(in case of INFINITY enter 32767):");
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  {
		printf("\nd[%d][%d]:",i,j);
		scanf("%d",d[i][j]);
	  }

	/* CALCULATION PART */

	for(k=0;k<n;k++)
	 {
		for(i=1;i<n;i++)
		 {
			if(d[i][k] < 32767)
			 {
				for(j=1;j<n;j++)
				 {
					if(d[j][k] < 32767)
					 {
						s=d[i][j]+d[j][k];
						 if(s < d[i][j])
							 d[i][j]=s;
						 else
							 continue;
					 }
				 }
			 }
		  }
	 }

	/* OUTPUT PART */

	for(i=0;i<n;i++)
	 {
		for(j=0;j<n;j++)
		  printf("%d",d[i][j]);
		printf("\n");
	 }
 getch();

} /* End Of MAIN */
