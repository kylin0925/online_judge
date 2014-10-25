/* @JUDGE_ID: 53xxxx 324 C++ */
#include <stdio.h>
#include <string.h>
int fa[1000]={0};
int num[10]={0};
int mul(int m)
{
    int i,c=0,d;
    for(i=999;i>=0;i--)
    {
        d=fa[i];
        fa[i]=(d*m+c)%10000;
        c=(d*m+c)/10000;
    }
}
int main(int argc, char* argv[])
{

   int n,i,j;
   char bu[5];
   while(1)
   {
     scanf("%d",&n);
     fa[1000-1]=1;
     if(n==0) break;
     for(i=1;i<=n;i++)
     {
         mul(i);
     }
     for(i=0;i<1000;i++)
     {
         if(fa[i]>0) break;
     }

     sprintf(bu,"%d",fa[i]);
     for(j=0;j<strlen(bu);j++)
     {num[bu[j]-'0']++;}
     for(j=i+1;j<1000;j++)
     {
        sprintf(bu,"%04d",fa[j]);
        num[bu[0]-'0']++;
        num[bu[1]-'0']++;
        num[bu[2]-'0']++;
        num[bu[3]-'0']++;
     }
     printf("%d! --\n",n);
     printf("   (0)%4d   (1)%4d   (2)%4d",num[0],num[1],num[2]);
     printf("   (3)%4d   (4)%4d\n",num[3],num[4]);
     printf("   (5)%4d   (6)%4d   (7)%4d",num[5],num[6],num[7]);
     printf("   (8)%4d   (9)%4d\n",num[8],num[9]);
     for(i=0;i<10;i++) num[i]=0;
     for(i=0;i<1000;i++) fa[i]=0;
   }
        return 0;
}
