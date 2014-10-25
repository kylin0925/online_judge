/* @JUDGE_ID: 53xxxx 498 C++ */
#include <stdio.h>
#include <string.h>
#include <math.h>
int main(int argc, char* argv[])
{
   unsigned long i=0,ix=0,j,k,sum;
   int c[1000],x[1000];
   char t[1000];
   char *p;
   while(1)
   {
      sum=0;
      i=0,ix=0;
      gets(t);
      p=strtok(t," ");
      sscanf(p,"%d",&c[i++]);
      while(p!=NULL)
      {
       p=strtok(NULL," ");
       if(p!=NULL)
        sscanf(p,"%d",&c[i++]);
      }
      if(gets(t)==NULL) return 0;
      p=strtok(t," ");
      sscanf(p,"%d",&x[ix++]);
      while(p!=NULL)
      {
       p=strtok(NULL," ");
       if(p!=NULL)
        sscanf(p,"%d",&x[ix++]);
      }
      for(k=0;k<i;k++)
      {
        if(x[0]!=0)
          sum+=c[k]*pow(x[0],i-k-1);
        else
       {
           if(i-1==0)
            sum+=c[k]*1;
        }
      }
      printf("%d ",sum);
      sum=0;
      for(j=1;j<ix;j++)
      {
        for(k=0;k<i;k++)
        {
          if(x[j]!=0)
           sum+=c[k]*pow(x[j],i-k-1);
          else
          {
           if(i-1==0)
            sum+=c[k]*1;
          }
        }
        printf(" %d",sum);
        sum=0;
      }
      printf("\n");
   }
        return 0;
}
