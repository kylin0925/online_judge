/* @JUDGE_ID: 53xxxx 574 C++ */
#include <stdio.h>
int list[20];
int sov[20];
int f,num;
int sol;
void tsov(int index,int value)
{
      int i;
      if(value==0)
      {
         f=1;
         for(i=0;i<sol;i++)
         {
            if(i>0) printf("+");
            printf("%d",sov[i]);
         }
         printf("\n");
         return;
      }
      for(i=index;i<num;i++)
      {
         while(i!=index && list[i]==list[i-1]) i++ ;
         if(list[i]<=value)
         {
            sov[sol]=list[i];
            sol++;
            tsov(i+1,value-list[i]);
            sol--;
         }
      }
}
int main(int argc, char* argv[])
{
    int tat,i,j,tmp;
    while(1)
    {
       scanf("%d %d",&tat,&num);
       f=0;
       if(!tat && !num) break;
       for(i=0;i<num;i++) scanf("%d",&list[i]);
       for(i=0;i<num;i++)
       {
           for(j=0;j<num;j++)
           {
               if(list[i]>list[j])
               {
                  tmp=list[j];
                  list[j]=list[i];
                  list[i]=tmp;
               }
           }
       }
       sol=0;
       printf("Sums of %d:\n",tat);
       tsov(0,tat);

       if(!f)
       {
          printf("NONE\n");
       }
    }
        return 0;
}
