/* @JUDGE_ID: 53xxxx 275 C++ */
#include <stdio.h>
#include <math.h>
int c[1500];
int f[1500];
int main(int argc, char* argv[])
{
    int x,y,tc,tf,zl,i,j,re,cc,cf,st,ter,ttf,ttc;
    int len;
    int pl;
    while(1)
    {
       for(i=0;i<1500;i++)
       {
         c[i]=f[i]=0;
       }
       scanf("%d %d",&x,&y);
       zl=0,re=0,cc=0,cf=0,ter=0;
       len=0;
       if(!x && !y) break;
       tc=x*10;
       f[cf++]=x;
       
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
         printf(".");
         pl++;
         for(i=0;i<zl;i++)
         {
            if(pl==51) printf("\n"),pl=1;
            printf("0");
            pl++;

         }
         for(i=0;i<len;i++)
         {
            if(pl==51) printf("\n"),pl=1;
            printf("%d",c[i]);
            pl++;
         }
         printf("\nThis expansion terminates.\n");
       }
       else if(re)
       {
         printf(".");
         pl++;

         for(i=0;i<zl;i++)
         {
            if(pl==51) printf("\n"),pl=1;
            printf("0");
            pl++;
         }
         for(i=0;i<len;i++)
         {
            if(pl==51) printf("\n"),pl=1;
            printf("%d",c[i]);
            pl++;
         }

         printf("\nThe last %d digits repeat forever.\n",len-st);
       }
    }
       return 0;
}
