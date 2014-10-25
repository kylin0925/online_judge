/* @JUDGE_ID: 53xxxx 107 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
int main()
{
    double hinit,lastno,notwork=0,toth=0,k,i,tt;
    unsigned long n,t;

    while(scanf("%lf %lf",&hinit,&lastno)==2)
    {
         if(hinit==0 && lastno==0) break;
         notwork=0;
         toth=0;
         if(hinit==1 && lastno==1){ printf("0 1\n");}
         else if((hinit-lastno)==1){ printf("1 %.0lf\n",hinit+lastno);}
         else
         {
             for(k=2;;k++)
             {
                 n=pow(lastno,1/k)+0.0000001;
                 t=pow((n+1),k);
                 if(t==hinit)
                 {
                    break;
                 }
              }
              tt=n;
              for(i=0;i<k;i++)
              {
                  notwork+=pow(tt,i);
                  toth+=pow(tt,i)*pow(tt+1,k-i);
              }
            printf("%.0lf %.0lf\n",notwork,toth+pow(tt,k));
          }
    }
        return 0;
}
/* END_OF_SOURCE_CODE */
