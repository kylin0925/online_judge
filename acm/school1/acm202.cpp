/* @JUDGE_ID: 53xxxx 202 C++ */
#include <stdio.h>
#include <math.h>
int c[1500];
int f[1500];
int main(int argc, char* argv[])
{
    int x,y,tc,tf,zl,i,j,re,cc,cf,st,ter,ttf,ttc;
    int len;
    int pl;
    int z;
    while(scanf("%d %d",&x,&y)==2)
    {
       for(i=0;i<1500;i++)
       {
         c[i]=f[i]=0;
       }

       zl=0,re=0,cc=0,cf=0,ter=0;
       len=0;
       
       if(x>=y)
       {
         z=x/y;
         tc=x%y;
         f[cf++]=tc;
         tc*=10;
       }
       else
       {
        z=0;
        tc=x*10;
        f[cf++]=x;
       }


       while(!re && !ter)
       {
         ttc=tc/y;
         tf=tc%y;
         if(tc==0){ ter=1;break;}
         for(i=0;i<=len;i++)
         {
            if(tf==f[i]){ re=1,st=i;break; }
         }
         if(!re)
         {
           c[cc++]=ttc;
           f[cf++]=tf;
         }
         else
         {
           c[cc]=ttc;
           f[cf]=tf;
         }
         len++;
          tc=tc%y*10;
       }
       pl=1;
       if(ter)
       {
         printf("%d/%d = %d.",x,y,z);
         pl++;

         for(i=0;i<len && i<50;i++)
         {
            printf("%d",c[i]);
         }
         printf("(0)\n");
         printf("   1 = number of digits in repeating cycle\n");
       }
       else if(re)
       {
         printf("%d/%d = %d.",x,y,z);
         pl++;
         for(i=0;i<len && i<50;i++)
         {
            if(i==st) printf("(");
            printf("%d",c[i]);

         }
         if(len>50){printf("...)\n");}
         else
         { printf(")\n");}
         printf("   %d = number of digits in repeating cycle\n",len-st);
       }
    }
       return 0;
}

