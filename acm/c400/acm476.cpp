/* @JUDGE_ID: 53xxxx 476 C++ */
#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
     double rx1[100],ry1[100],rx2[100],ry2[100];
     double x,y;
     int r=0,i,p=1,hit=0;
     char o;
     while(1)
     {
        scanf("%c",&o);
        if(o=='r')
        {
         scanf("%lf %lf %lf %lf\n",&rx1[r],&ry1[r],&rx2[r],&ry2[r]);
         r++;
        }
        else if(o=='*') break;
     }
     while(1)
     {
        scanf("%lf %lf",&x,&y);
        hit=0;
        if(x==9999.9&&y==9999.9) break;
        for(i=0;i<r;i++)
        {
         if(x>rx1[i] && x<rx2[i] && y<ry1[i] && y>ry2[i])
         {
          printf("Point %d is contained in figure %d\n",p,i+1);
          hit=1;
         }
        }
        if(!hit)
        {
         printf("Point %d is not contained in any figure\n",p);
        }
        p++;
     }
        return 0;
}

