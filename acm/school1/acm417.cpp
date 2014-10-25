/* @JUDGE_ID: 53xxxx 417 C++ */
#include <stdio.h>
#include <string.h>
int test(char tstr[])
{
    int i;
    for(i=1;i<strlen(tstr);i++)
    {
         if(tstr[i-1]>=tstr[i]) return 0;
    }
    return 1;
}
int cam(int n,int r)
{
    int i,j;
    int sum=1;
    for(i=n,j=1;i>(n-r);i--,j++)
    {
        sum=(sum*i)/j;
    }
  return sum;

}
int main()
{
   char in[10];
   int sum,len,i,j,la;
   while(gets(in))
   {
       sum=0;
       len=strlen(in);
       if(!test(in)){ printf("0\n");continue;}
       for(i=1;i<len;i++)
       {
         sum+=cam(26,i);
       }

       for(i=0;i<len;i++)
       {
          for(j='a'+i,la=i+1;j<in[i];j++,la++)
          {
             if(i>0 && j<=in[i-1]) continue;
             sum+=cam(26-la,len-i-1);
          }
       }
       printf("%d\n",sum+1);
   }
}
