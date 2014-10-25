/* @JUDGE_ID: 53xxxx 386 C++ */
#include <math.h>
#include <stdio.h>
long rabc;

int main(void)
{
    long b,c,d,com;
    long   a;
    long con=0;

    for(a=1;a<=200;a++)
    {
      rabc=a*a*a;
       for(b=2;b<=a;b++)
       {
           for(c=b+1;c<=a;c++)
           {
               for(d=c+1;d<=a;d++)
               {
                   com=b*b*b+c*c*c+d*d*d;
                   if(com==rabc && b!=c && c!=d && d!=b)
                   {
                      con++;
                      printf("Cube = %.0lf, Triple = (%d,%d,%d)\n",pow((double)com,1.0/3.0),b,c,d);
                   }
               }
            }
        }
      }
   
     return 0;
}

