/* @JUDGE_ID: 53xxxx 190 C++ */
#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
    long double px1,py1,px2,py2,px3,py3;
    long double d,e,f,h,k,r,c1,c2,c3;
    long double d1,e1,f1,d2,e2,f2,d3,e3,f3,del,to;
    while(scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&px1,&py1,&px2,&py2,&px3,&py3)==6)
    {
          d1=px1,e1=py1,f1=1;
          d2=px2,e2=py2,f2=1;
          d3=px3,e3=py3,f3=1;
          c1=-1*(px1*px1+py1*py1);
          c2=-1*(px2*px2+py2*py2);
          c3=-1*(px3*px3+py3*py3);

          del=(d1*e2+e1*d3+d2*e3)-(e2*d3+e3*d1+e1*d2);
          d  =((c1*e2+e1*c3+c2*e3)-(e2*c3+e3*c1+e1*c2))/del;
          e  =((d1*c2+c1*d3+d2*c3)-(c2*d3+c3*d1+c1*d2))/del;
          f  =((d1*e2*c3+e1*c2*d3+d2*e3*c1)-(c1*e2*d3+c2*e3*d1+e1*d2*c3))/del;
          h  =d/2;
          k  =e/2;
          r  =sqrt((px1+h)*(px1+h)+(py1+k)*(py1+k));
          printf("(x");
          if(h<0)
          {

                  printf("%.3Lf",h);
          }
          else
          {
                  printf("+%.3Lf",h);
          }
          printf(")^2+(y");
          if(k<0)
          {
                   printf("%.3Lf",k);
          }
          else
          {
                  printf("+%.3Lf",k);
          }
          printf(")^2=");
          printf("%.3Lf^2\n",r);
          printf("x^2+y^2");
          if(d<0)
          {
                  printf("%.3Lfx",d);
          }
          else
          {
                  printf("+%.3Lfx",d);
          }
          if(e<0)
          {
                  printf("%.3Lfy",e);
          }
          else
          {
                  printf("+%.3Lfy",e);
          }
          if(f<0)
          {
                  printf("%.3Lf",f);
          }
          else
          {
                  printf("+%.3Lf",f);
          }
          printf("=0\n\n");

    }
        return 0;
}
