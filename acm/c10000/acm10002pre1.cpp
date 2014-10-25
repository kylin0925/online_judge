/* @JUDGE_ID: 53xxxx 10002 C++ */
/*@BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point{
        double x;
        double y;
};
point in[110],node[110],pa[110];
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
int sort()
{
        double ang[110]={0.0},tmp;
        int i,j,max,top,min;
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
                      if(ang[j]>ang[j+1]){
                         tmp=ang[j]; ang[j]=ang[j+1]; ang[j+1]=tmp;
                         swap(&in[j],&in[j+1]);
                      }
                }
        }
        max=0;
        for(i=1;i<n;i++)
        {
                if(ang[i]==ang[0] && in[i].x>in[0].x)
                {
                    if(in[i].x>in[max].x) max=i;
                }
        }
        min=0;
        for(i=1;i<n;i++)
        {
                if(ang[i]==ang[0] && in[i].x<in[0].x)
                {
                    if(in[i].x<in[min].x) min=i;
                }
        }
        top=0;
        for(i=1;i<n;i++)
        {
                if(in[i].x==in[0].x)
                {
                    if(in[i].y>in[top].y) top=i;
                }
        }
        node[0]=in[0];
        for(i=1,j=1;i<n;i++)
        {
            if(ang[i]==ang[0] &&(i==max || i==min || i==top)) node[j++]=in[i];
            else if(ang[i]!=ang[0])
                node[j++]=in[i];
        }
        return j;
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
void cont(int tn)
{
        double a,ta=0,ax,ay;
        int i;
        ax=ay=0;
        for(i=1;i<tn-1;i++)
        {
             a=ca(pa[0],pa[i],pa[i+1]);
             ax+=a*(pa[0].x+pa[i].x+pa[i+1].x)/3.0;
             ay+=a*(pa[0].y+pa[i].y+pa[i+1].y)/3.0;
             ta+=a;
        }
        printf("%.3lf %.3lf\n",ax/ta+0.000005,ay/ta+0.000005);
}
int ccw(point p0,point p1,point p2)
{
  double dx1,dx2,dy1,dy2;
  dx1=p1.x-p0.x;
  dy1=p1.y-p0.y;
  dx2=p2.x-p0.x;
  dy2=p2.y-p0.y;
  if((dx1*dy2)>(dx2*dy1)) return 0;
  if((dx1*dy2)<=(dx2*dy1)) return 1;
}
int grahamscan(int n)
{
        int i,x,y,m,min;
        point tmp;
        /* printf("---------------------\n");
        for(x=0;x<n;x++) printf("%lf %lf\n",p[x].x,p[x].y); */
        pa[0]=node[0];
        pa[1]=node[1];
        for(m=1,i=2;i<n;i++)
        {
         while(ccw(pa[m-1],pa[m],node[i]))
         {
                 m--;
         }
         pa[++m]=node[i];
         /*printf("---------------------\n");
         for(x=0;x<=i;x++) printf("%lf %lf\n",o[x].x,o[x].y); */
        }
    return m+1;
}
int main(int argc, char* argv[])
{
        int tn;
        while(scanf("%d",&n)==1)
        {
                if(n<3) break;
                get_p();
                tn=sort();
                tn=grahamscan(tn);
                cont(tn);
        }
        return 0;
}
/*@END_OF_SOURCE_CODE*/
