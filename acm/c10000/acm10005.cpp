/* @JUDGE_ID: 53xxxx 10005 C*/
/*@begin_of_source_code*/
#include <stdio.h>
#include <math.h>
double max(double a,double b){return (a>b)?a:b;}
int n;
double x[150],y[150];
double r;
int main(int argc, char* argv[])
{
   int i,j,k,f;
   double a,b,c,ml,s,p;
   double aa,bb,cc;
   while(1)
   {
        scanf("%d",&n);
        if(!n) break;
        f=0;
        for(i=0;i<n;i++)
        {
           scanf("%lf %lf",&x[i],&y[i]);
        }
        scanf("%lf",&r);
        f=0;
        for(i=0;i<n-2 && !f;i++)
        {
           for(j=i+1;j<n-1 && !f;j++)
           {
              for(k=j+1;k<n && !f;k++)
              {
                 aa=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
                 a=sqrt(aa);
                 bb=(x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]);
                 b=sqrt(bb);
                 cc=(x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]);
                 c=sqrt(cc);
                 if(((aa)>(bb+cc))||((bb)>(aa+cc))||((cc)>(bb+aa)))
                 {
                    ml=max(max(a,b),c);
                    if(ml>2*r) f=1;
                 }
                 else
                 {
                   p=(a+b+c)/2;
                   s=sqrt(p*(p-a)*(p-b)*(p-c));
                   ml=((a*b*c)/(4*s));
                   if(ml>r) f=1;
                 }

              }
           }
        }
        if(!f) printf("The polygon can be packed in the circle.\n");
        else
           printf("There is no way of packing that polygon.\n");
   }
        return 0;
}
/*@end_of_source_code*/

