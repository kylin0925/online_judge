/* @JUDGE_ID: 53xxxx 477 C++ */
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
     double rx1[100],ry1[100],rx2[100],ry2[100];
     double crx[100],cry[100],rlen[100];
     double x,y;
     int r=0,i,p=1,hit=0,c=0;
     char o;
     for(i=0;i<100;i++)
     {
         rx1[i]=100000.0,ry1[i]=100000.0,rx2[i]=100000.0,ry2[i]=100000.0;
         crx[i]=100000.0,cry[i]=100000.0,rlen[i]=100000.0;
     }
     while(1)
     {
        scanf("%c",&o);
        if(o=='r')
        {
         scanf("%lf %lf %lf %lf\n",&rx1[r],&ry1[r],&rx2[r],&ry2[r]);
         r++;
        }
        else if(o=='c')
        {
          scanf("%lf %lf %lf\n",&crx[r],&cry[r],&rlen[r]);
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
         if(rx1[i]!=100000)
         {
          if(x>rx1[i] && x<rx2[i] && y<ry1[i] && y>ry2[i])
          {
           printf("Point %d is contained in figure %d\n",p,i+1);
           hit=1;
          }
         } 
         else if(crx[i]!=100000)
         {
          if(((x-crx[i])*(x-crx[i])+(y-cry[i])*(y-cry[i]))<(rlen[i]*rlen[i]))
          {
           printf("Point %d is contained in figure %d\n",p,i+1);
           hit=1;
          }
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
