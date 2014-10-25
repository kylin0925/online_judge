/*@JUDGE_ID:5392yr 498 C++   */
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[])
{
    char buff[300],b[300];
    char *t;
    int  c[500]={0},x[500]={0},ic=0,ix=0;
    int i,j;
    long sum=0;
    gets(buff);
    while(gets(b))
    {
      t=strtok(buff," ");
      sscanf(t,"%d",&c[ic++]);
      while(t!=NULL)
      {
         t=strtok(NULL," ");
         if(t!=NULL)
          sscanf(t,"%d",&c[ic++]);
      }
      t=strtok(b," ");
      sscanf(t,"%d",&x[ix++]);
      while(t!=NULL)
      {
         t=strtok(NULL," ");
         if(t!=NULL)
          sscanf(t,"%d",&x[ix++]);
      }
      for(i=0;i<ic;i++)
      {
          if(c[i]==0)
          {
             if((ic-i-1)==0)
             {
               sum+=c[i];
             }
          }
          else
          {
            if(x[0]==0)
            {
             if((ic-i-1)==0)
             {
               sum+=c[i];
             }
            }
            else
            {
             sum+=c[i]*pow(x[0],ic-i-1);
            }
          }
      }
      printf("%d",sum);
      sum=0;
      for(i=1;i<ix;i++)
      {
         for(j=0;j<ic;j++)
         {
            if(c[j]==0)
            {
               if((ic-j-1)==0)
                sum+=c[j];
            }
            else
            {
              if(x[i]==0)
              {
               if((ic-j-1)==0)
                sum+=c[j];
              }
              else
              {
               sum+=c[j]*pow(x[i],ic-j-1);
              }
            }
         }
         printf(" %d",sum);
         sum=0;
      }
      printf("\n");
      gets(buff);
      ic=0,ix=0;
      sum=0;
    }
        return 0;
}
 
