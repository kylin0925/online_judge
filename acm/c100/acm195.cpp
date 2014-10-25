/* @JUDGE_ID:53xxxx 195 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>
char p[1000],pp[1000];
int len;
void perm(int i)
{
      int j,k,h;
      char t;
      int num[52]={0};
      if(i<len)
      {
          for(j=i;j<=len;j++)
          {
               t=p[j];
               for(k=j;k>i;k--)
               {
                   p[k]=p[k-1];
               }
               p[i]=t;
               if((p[i]>='a')&&(p[i]<='z'))
               {
                  h= p[i]-'a';
                  num[h]++;
               }
               else
               {
                   h= p[i]-'A'+26;
                   num[h]++;
               }
               if(num[h]<=1){
                 perm(i+1);
               }  
               for(k=i;k<j;k++)
               {
                    p[k]=p[k+1];
               }
               p[j]=t;

          }
      }
      else
      {
           for(j=1;j<=len;j++)
           {
                printf("%c",p[j]);
           }
           printf("\n");
      }
}
int main(int argc, char* argv[])
{
      int n,i,j;
      char tmp;
      scanf("%d",&n);
      for(;n>0;n--)
      {
          scanf("%s",p);
          len=strlen(p);

          for(i=len;i>0;i--)
          {
              p[i]=p[i-1];
          }
          strcpy(pp,p);
          for(i=1;i<=len;i++)
          {
              for(j=1;j<=len;j++)
              {
                  if(p[i]<=p[j])
                  {
                      tmp=p[i];
                      p[i]=p[j];
                      p[j]=tmp;
                  }
              }
          }
          perm(1);
      }
        return 0;
}
/* @END_OF_SOURCE_CODE */


