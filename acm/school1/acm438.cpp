/* @JUDGE_ID: 53xxxx 438 C++ */
#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
   long double px1,py1,px2,py2,px3,py3;
   long double l1,l2,l3,del,s,r,rr;
   while(scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&px1,&py1,&px2,&py2,&px3,&py3)!=EOF)
   {
        l1=sqrt((px2-px1)*(px2-px1)+(py2-py1)*(py2-py1));
        l2=sqrt((px2-px3)*(px2-px3)+(py2-py3)*(py2-py3));
        l3=sqrt((px3-px1)*(px3-px1)+(py3-py1)*(py3-py1));
        s=(l1+l2+l3)/2;
        del=sqrt(s*(s-l1)*(s-l2)*(s-l3));
        r=l1*l2*l3/(4*del);
        rr=2*r*3.141592653589793;
        printf("%.2Lf\n",rr);
   }
        return 0;
}
 
