#include<stdio.h>
#include<stdlib.h>
 typedef struct animal{
  int cost;
 int max_area;

  }animal[3];

  int main()
  {
      int max_cost=0,min_cost=0,total_area,i,j=0,k=0,m=0,rest=0, h=0, c=0,a=0,total_cost=0;
      int har[2],car[2],aq[2];
      animal an;
      printf("\nenter the cost::");
      for(i=0;i<3;i++)
      {
          scanf("%d",&an[i].cost);

      }
      printf("\nenter the maximum area::");
      for(i=0;i<3;i++){
      scanf("%d", &an[i].max_area);
      }
      printf("\nthe array of har::");
      for(i=0;i<2;i++){
      scanf("%d",&har[i]);

      }
      printf("\nenter the arrat of car:");

      for(i=0;i<2;i++)
      {
          scanf("%d",&car[i]);
      }

      printf("\nenter the array of aq::");
      for(i=0;i<2;i++)
      {
          scanf("%d",&aq[i]);
      }

      printf("\nthe total area::");
      scanf("%d",&total_area);
      max_cost=an[0].cost;
      for(i=0;i<3;i++)
      {
          if(an[i].cost>max_cost)
          {
              max_cost= an[i].cost;
              j=i;
          }
      }
      min_cost=an[0].cost;
      for(i=0;i<3;i++)
      {
          if(an[i].cost<min_cost)
         {
              min_cost= an[i].cost;
              k=i;
          }
      }
      //printf("%d%d",an[j].cost,j);
      //printf("%d",an[k].cost);
        if(j==0){
          h=har[1] * har[0];
          rest= total_area - h;
        }
        if(j==1){
            c= car[1] * car[0];
            rest= total_area -c;
        }
        if(j==2){
            a= aq[1]*aq[0];
            rest= total_area -a;
        }
        if(k==0){
            h= an[k].max_area;
            rest= rest - h;
        }else
        if(k==1){
            c= an[k].max_area;
            rest= rest - c;
        }else
        if(k==2){
            a= an[k].max_area;
            rest= rest - a;
        }
        for(i=0;i<3;i++){
            if(i==j || i==k){
                continue;
            }else{
            m= i;
            //printf("%d",an[m].cost);
            }
        }
        if(m==0)
        {
            h=rest;
        }
        if(m==1)
        {
            c=rest;
        }
        if(m==2)
        {
            a=rest;
        }
        total_cost=h*an[0].cost + c* an[1].cost + a* an[2].cost;
        printf("total cost=%d",total_cost);
        printf("\n%d\n%d\n%d",h,c,a);
      return 0;
  }