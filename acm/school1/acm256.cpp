/* @JUDGE_ID: 53xxxx 256 C++ */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
     int n,j,i,x,max,num,na1,na2;
     char buffer[100],n1[50],n2[50];
     for(i=0;i<100;buffer[i]='\0',i++) ;
     while(scanf("%d",&n)==1)
     {
         max=sqrt(pow(10,n)-1);
         for(j=0;j<=max;j++)
         {
             num=j*j;
             sprintf(buffer,"%0*d",n,num);
             for(i=0;i<n/2;i++)
             {
                  n1[i]=buffer[i];
             }
             n1[i]='\0';
             for(x=0,i=n/2;i<n;x++,i++)
             {
                  n2[x]=buffer[i];
             }
             n2[x]='\0';
             na1=atoi(n1);
             na2=atoi(n2);
             if((na1+na2)*(na1+na2)==num){ printf("%s\n",buffer);}
         }
         for(i=0;i<100;buffer[i]='\0',i++) ;
     }
        return 0;
}
