/* @JUDGE_ID: 53xxxx 495 C++ */
#include <stdio.h>
#include <math.h>
int main()
{
    double b,c,d,com,su;
    long a,bc,cc;
    char *ru;
    //b=3,c=4,d=5;
    for(b=2;b<=200;b++)
    {
        for(c=2;c<=200;c++)
        {
            for(d=2;d<=200;d++)
            {
              com=pow(pow(b,3.0)+pow(c,3.0)+pow(d,3.0),1.0/3.0);
              a=pow(pow(com,3.0)+0.00001,1.0/3.0);
                a*=1000000;
              com*=1000000;
              cc=com-a;
              if(cc==0)
              {
               printf("Cube = %d, Triple = (%.0lf,%.0lf,%.0lf)\n",a,b,c,d);
              }
            }
        }
    }
        return 0;
}
