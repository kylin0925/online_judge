/* @JUDGE_ID: 53xxxx 478 C++ */
#include <stdio.h>
#include <math.h>
#include <string.h>
int main(int argc, char* argv[])
{
     double rx1[100],ry1[100],rx2[100],ry2[100];
     double crx[100],cry[100],rlen[100];
     double tx1[100],tx2[100],tx3[100],ty1[100],ty2[100],ty3[100];
     double x,y;
     double ta,tat;
     int r=0,i,p=1,hit=0,c=0;
     char o;
     char t1[30],t2[30];
     for(i=0;i<100;i++)
     {
         rx1[i]=100000.0,ry1[i]=100000.0,rx2[i]=100000.0,ry2[i]=100000.0;
         crx[i]=100000.0,cry[i]=100000.0,rlen[i]=100000.0;
         tx1[i]=100000.0,tx2[i]=100000.0;
         tx3[i]=100000.0,ty1[i]=100000.0;
         ty2[i]=100000.0,ty3[i]=100000.0;
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
        else if(o=='t')
        {
          scanf("%lf %lf %lf %lf %lf %lf\n",&tx1[r], \
          &ty1[r],&tx2[r],&ty2[r],&tx3[r],&ty3[r]);
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
         else if(tx1[i]!=100000)
         {
           ta=fabs(((tx1[i]*ty2[i]+tx2[i]*ty3[i]+tx3[i]*ty1[i])-\
           (ty1[i]*tx2[i]+ty2[i]*tx3[i]+ty3[i]*tx1[i]))/2);
           tat=0;
           tat+=fabs(((x*ty1[i]+tx1[i]*ty2[i]+tx2[i]*y)- \
           (y*tx1[i]+ty1[i]*tx2[i]+ty2[i]*x))/2);
           tat+=fabs(((x*ty2[i]+tx2[i]*ty3[i]+tx3[i]*y)- \
           (y*tx2[i]+ty2[i]*tx3[i]+ty3[i]*x))/2);
           tat+=fabs(((x*ty1[i]+tx1[i]*ty3[i]+tx3[i]*y)- \
           (y*tx1[i]+ty1[i]*tx3[i]+ty3[i]*x))/2);
           sprintf(t1,"%.3lf",ta);
           sprintf(t2,"%.3lf",tat);
           if(!strcmp(t1,t2))
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
