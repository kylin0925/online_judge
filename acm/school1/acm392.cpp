/* @JUDGE_ID: 53xxxx 392 C++ */
#include <stdio.h>
int main()
{
   int num[9],i,j;
   while(scanf("%d%d%d%d%d%d%d%d%d", \
   &num[8],&num[7],&num[6],&num[5],&num[4],&num[3],&num[2],&num[1],&num[0])==9)
   {
    for(i=8;i>=0;i--)
    {
       if(num[i]!=0) break;
    }
    if(i>0)
    {
     if(i==1)
     {
       if(num[i]==1)
       {
         printf("x",i);
       }
       else if(num[i]>1)
        printf("%dx",num[i],i);
       else if(num[i]==-1)
         printf("-x",i);
       else
        printf("%dx",num[i],i);
     }
     else
     {
       if(num[i]==1)
       {
         printf("x^%d",i);
       }
       else if(num[i]>1)
        printf("%dx^%d",num[i],i);
       else if(num[i]==-1)
         printf("-x^%d",i);
       else
        printf("%dx^%d",num[i],i);
     }
      i--;

      for(;i>0;i--)
      {
         if(i==1)
         {
            if(num[1]>0)
            {
               if(num[1]!=1)
                printf(" + %dx",num[i]);
               else
                printf(" + x");
            }
            else if(num[1]<0)
            {
               if(num[1]!=-1)
                printf(" - %dx",0-num[i]);
               else
                printf(" - x");
            }

         }
         else if(num[i]!=0)
         {
             if(num[i]>0)
             {
               if(num[i]>1)
                printf(" + %dx^%d",num[i],i);
               else
                printf(" + x^%d",i);

             }
             else if(num[i]<0)
             {
               if(num[i]<-1)
                printf(" - %dx^%d",0-num[i],i);
               else
                printf(" - x^%d",i);
             }
          }
      }
      if(num[0]!=0)
      {
         if(num[0]>0)
           printf(" + %d",num[0]);
         else if(num[0]<0)
           printf(" - %d",(0-num[0]));

      }
      printf("\n");
    }
    else if(i==0 && num[0]!=0)
    {
      if(num[0]>0)
       printf("%d\n",num[0]);
      else if(num[0]<0)
       printf("%d\n",num[0]);
    }
    else
    {
      printf("0\n");
    }
   }
}
