/* @JUDGE_ID: 53xxxx 573 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
int main(int argc, char* argv[])
{
    double h,u,d,f,m,now;
    int day;
    while(1)
    {
       scanf("%lf %lf %lf %lf",&h,&u,&d,&f);
       day=1;
       if(!h) break;
       m=u*f/100;
       now=0;
       while(1)
       {
         now+=u;
         if(now>h)
         {
         printf("success on day %d\n",day);
         break;
         }
         now-=d;
         if(now<0.0)
         {
         printf("failure on day %d\n",day);
         break;
         }
         u-=m;
         if(u<0.0) u=0;
         day++;

       }
    }
        return 0;
}
/* END_OF_SOURCE_CODE */
