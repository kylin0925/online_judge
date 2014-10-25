/* @JUDGE_ID: 53xxxx 10002 C++ */
/*@BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point{
        double x;
        double y;
};
point in[110];
int n;
int minp;
void swap(point *a,point *b)
{
     point tmp;
     tmp=*a;
     *a=*b;
     *b=tmp;
}
void get_p()
{
        int i,j;
        minp=0;
        for(i=0,j=n;j;i++,j--)
        {
                scanf("%lf %lf",&in[i].x,&in[i].y);
                if(in[i].y<in[minp].y) minp=i;
                else if(in[i].y==in[minp].y)
                {
                        if(in[i].x<in[minp].x) minp=i;
                }
        }
}
double theata(point a,point b)
{
        double dx,dy,ax,ay;
        double tmp;
        dx=b.x-a.x;
        ax=fabs(dx);
        dy=b.y-a.y;
        ay=fabs(dy);
        tmp=((ax+ay)==0)?0:(double)(dy/(ax+ay));
        if(dx<0) tmp=2-tmp;
        else if(dy<0) tmp=4+tmp;
        tmp=tmp*90;
        return tmp;
}
void sort()
{
        double ang[110]={0.0},tmp;
        int i,j;
        point tmp1[110];
        swap(&in[0],&in[minp]);
        for(i=1;i<n;i++)
        {
                ang[i]=theata(in[0],in[i]);
        }
        for(i=n-1;i>0;i--)
        {
                for(j=1;j<i;j++)
                {
                      if(ang[j]>ang[j+1])
                      {
                         tmp=ang[j];
                         ang[j]=ang[j+1];
                         ang[j+1]=tmp;
                         swap(&in[j],&in[j+1]);
                      }
                      else if(ang[j]==ang[j+1])
                      {
                         if((int)in[j].x>=0 && in[j].x>in[j+1].x)
                         {
                                tmp=ang[j];
                                ang[j]=ang[j+1];
                                ang[j+1]=tmp;
                                swap(&in[j],&in[j+1]);
                         }
                         if(in[j].x<0.0 && in[j].x<in[j+1].x)
                         {
                                tmp=ang[j];
                                ang[j]=ang[j+1];
                                ang[j+1]=tmp;
                                swap(&in[j],&in[j+1]);
                         }
                         else if(in[j].x==in[j+1].x)
                         {
                                if(in[j].y<in[j+1].y)
                                {
                                        tmp=ang[j];
                                        ang[j]=ang[j+1];
                                        ang[j+1]=tmp;
                                        swap(&in[j],&in[j+1]);
                                }
                         }
                      }

                }
        }
}
double ca(point a,point b,point c)
{
        // ax bx cx  ax
        // ay by cy  ay
        double area;
        area=a.x*b.y+b.x*c.y+c.x*a.y;
        area-=b.x*a.y+c.x*b.y+a.x*c.y;
        fabs(area);
        return area*0.5;
}
void cont()
{
        double a,ta=0,ax,ay;
        int i;
        ax=ay=0;
        for(i=1;i<n-1;i++)
        {
             a=ca(in[0],in[i],in[i+1]);
             ax+=a*(in[0].x+in[i].x+in[i+1].x)/3.0;
             ay+=a*(in[0].y+in[i].y+in[i+1].y)/3.0;
             ta+=a;
        }
        printf("%.3lf %.3lf\n",ax/ta,ay/ta);
}
int main(int argc, char* argv[])
{
        while(scanf("%d",&n)==1)
        {
                if(n<3) break;
                get_p();
                sort();
                cont();
        }
        return 0;
}
/*@END_OF_SOURCE_CODE*/
