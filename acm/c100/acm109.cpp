/* @JUDGE_ID: 53xxxx 109 C++ */
#include <stdio.h>
#include <math.h>
typedef struct tpoint
{
  double x;
  double y;
}point;
point pa[200][200];
int ccw(point p0,point p1,point p2)
{
  double dx1,dx2,dy1,dy2;
  dx1=p1.x-p0.x;
  dy1=p1.y-p0.y;
  dx2=p2.x-p0.x;
  dy2=p2.y-p0.y;
  if((dx1*dy2)>(dx2*dy1)) return 0;
  if((dx1*dy2)<=(dx2*dx1)) return 1;
}
double theata(point p1,point p2)
{
 double dx,dy,ax,ay;
 double tmp;
 dx=p2.x-p1.x;
 ax=fabs(dx);
 dy=p2.y-p1.y;
 ay=fabs(dy);
 tmp=(((ax+ay) == 0) ? 0 : (double)(dy/(ax+ay)));
 if(dx<0) tmp=2-tmp;
 else if(dy<0) tmp=4+tmp;
 return tmp*90;
}

double area(int n,point p[])
{
      int i;
      double a=0;
      for(i=1;i<n;i++)
      {
         a+=(p[i-1].x*p[i].y-p[i].x*p[i-1].y);
      }
      a+=(p[n-1].x*p[0].y-p[0].x*p[n-1].y);
      a/=2;
      return a;
}
int in(int n,point t,point p[])
{
    double a,b=0;
    int i,j;
    a=area(n,p);
    for(i=0;i<n-1;i++)
    {
      b+=fabs((t.x*p[i].y+p[i].x*p[i+1].y+p[i+1].x*t.y) \
        -(t.y*p[i].x+p[i].y*p[i+1].x+p[i+1].y*t.x))/2;
    }
    b+=fabs((t.x*p[n-1].y+p[n-1].x*p[0].y+p[0].x*t.y)-  \
             (t.y*p[n-1].x+p[n-1].y*p[0].x+p[0].y*t.x))/2;
    if(((int)(a*1000))==((int)(b*1000))) return 1;
    else
      return 0;
}
int grah_scan(int n,int c,point p[])
{
    int i,x,y,m,min;
    point tmp;
   /* printf("---------------------\n");
    for(x=0;x<n;x++) printf("%lf %lf\n",p[x].x,p[x].y); */
    pa[c][0]=p[0];
    pa[c][1]=p[1];
    for(m=1,i=2;i<n;i++)
    {

        while(ccw(pa[c][m-1],pa[c][m],p[i]))
        {
          m--;
        }
        pa[c][++m]=p[i];
        /*printf("---------------------\n");
        for(x=0;x<=i;x++) printf("%lf %lf\n",o[x].x,o[x].y); */
    }
    return m+1;
}
int sort(int n,point p[],point o[])
{
   int i,j,min=0,max=0,x;
   double t[200],te;
   point tmp;

   for(min=0,i=1;i<n;i++)
      if(p[i].y<p[min].y) min=i;
    for(i=0;i<n;i++)
    {
       if(p[i].y==p[min].y)
       {
          if(p[i].x<p[min].x) min=i;
       }
    }
    p[n]=p[min];
    tmp=p[0];
    p[0]=p[min];
    p[min]=tmp;
    t[0]=0;
    for(i=1;i<n;i++)
      t[i]=theata(p[0],p[i]);
    for(i=1;i<n;i++)
    {
       for(j=1;j<n;j++)
       {
          if(t[i]<t[j])
          {
             te=t[i];  t[i]=t[j]; t[j]=te;
             tmp=p[i]; p[i]=p[j]; p[j]=tmp;
          }
       }
    }
    /*printf("---------------------\n");
    for(x=0;x<n;x++) printf("%lf %lf\n",p[x].x,p[x].y);*/
    for(i=1;i<n;i++)
    {
       if((p[0].y==p[i].y)&&(p[i].x-p[0].x)>(p[max].x-p[0].x)) max=i;
    }
    for(i=1;i<n;i++)
    {
      if((p[i].y==p[0].y)&&(p[i].x<p[max].x))
       t[i]=-999;
    }
    min=0;
    for(i=1;i<n;i++)
    {
       if((p[0].x==p[i].x)&&(p[i].y-p[0].y)<(p[min].x-p[0].x)) min=i;
    }
    for(i=1;i<min;i++)
    {
      if((p[i].x==p[0].x)&&(p[i].y<p[max].y))
        t[i]=-999;
    }
    x=n;
    for(i=0,j=0;i<n;i++)
    {
      if(t[i]!=-999)
       o[j++]=p[i];
      else
       x--;
    }
    return x;
}
int main(int argc, char **argv)
{
    int n,i,j,v[200],c=0;
    double sucd=0;
    point test;
    point tmp[200],o1[200];
    while(1)
    {
    	scanf("%d",&n);
    	if(n==-1) break;
    	for(i=0;i<n;i++)
    	{
    		scanf("%lf %lf",&tmp[i].x,&tmp[i].y);
    	}
    	n=sort(n,tmp,o1);
    	v[c++]=grah_scan(n,c,o1);
    }
    while(scanf("%lf %lf",&test.x,&test.y)==2)
    {
       for(i=0;i<c;i++)
       {
         if(in(v[i],test,pa[i]) && v[i]>0)
           sucd+=area(v[i],pa[i]),v[i]=0;
       }
    }
    printf("%.2lf\n",sucd);
    return 0;
}
