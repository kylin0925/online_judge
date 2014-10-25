/* @JUDGE_ID: 53xxxx 726 C++ */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char known[10000000];
char encoded[10000000];
int lk[30]={0};
int uk[30]={0};
int l[30]={0};
int u[30]={0};
int kch[26]={0};
int kchu[26]={0};
int ech[26]={0};
int echu[26]={0};

int main(int argc, char* argv[])
{
    int i,j,tmp;
    while(gets(known))
    {
       if(known[0]!='\0') break;
    }
    while(gets(encoded))
    {
       if(encoded[0]!='\0') break;
    }
    for(i=0;i<26;i++)
    {
        kch[i]=ech[i]=i;
        kchu[i]=echu[i]=i;
    }
    for(i=0;i<strlen(known);i++)
    {
       if(islower(known[i]))
       {
          lk[known[i]-'a']++;
       }
       if(isupper(known[i]))
       {
         uk[known[i]-'A']++;
       }
    }
    for(i=0;i<strlen(encoded);i++)
    {
       if(islower(encoded[i]))
       {
          l[encoded[i]-'a']++;
       }
       if(isupper(known[i]))
       {
          u[encoded[i]-'A']++;
       }
    }
    for(i=0;i<26;i++)
    {
            for(j=0;j<26;j++)
            {
                if(uk[i]>uk[j])
                {
                   tmp=uk[i];uk[i]=uk[j];uk[j]=tmp;
                   tmp=kchu[i];kchu[i]=kchu[j];kchu[j]=tmp;
                }
                else if((uk[i]==uk[j])&&(kchu[i]>kchu[j]))
                {
                   tmp=kchu[i];kchu[i]=kchu[j];kchu[j]=tmp;
                }
                if(lk[i]>lk[j])
                {
                   tmp=lk[i];lk[i]=lk[j];lk[j]=tmp;
                   tmp=kch[i];kch[i]=kch[j];kch[j]=tmp;
                }
                else if((lk[i]==lk[j])&&(kch[i]>kch[j]))
                {
                   tmp=kch[i];kch[i]=kch[j];kch[j]=tmp;
                }
            }
    }
    for(i=0;i<26;i++)
    {
            for(j=0;j<26;j++)
            {
                if(u[i]>u[j])
                {
                   tmp=u[i];u[i]=u[j];u[j]=tmp;
                   tmp=echu[i];echu[i]=echu[j];echu[j]=tmp;
                }
                else if((u[i]==u[j])&&(echu[i]>echu[j]))
                {
                   tmp=echu[i];echu[i]=echu[j];echu[j]=tmp;
                }
                if(l[i]>l[j])
                {
                   tmp=l[i]; l[i]=l[j]; l[j]=tmp;
                   tmp=ech[i];ech[i]=ech[j];ech[j]=tmp;
                }
                else if((l[i]==l[j])&&(ech[i]>ech[j]))
                {
                   tmp=ech[i];ech[i]=ech[j];ech[j]=tmp;
                }
            }
    }
    for(i=0;i<strlen(encoded);i++)
    {
        if(islower(encoded[i]))
        {
           for(j=0;j<30;j++)
           {
              if(encoded[i]==ech[j]+'a')
              {
                 printf("%c",kch[j]+'a');
                 break;
              }
           }
        }
        else if(isupper(encoded[i]))
        {
           for(j=0;j<30;j++)
           {
              if(encoded[i]==echu[j]+'A')
              {
                 printf("%c",kchu[j]+'A');
                 break;
              }
           }
        }
        else
        {
           printf("%c",encoded[i]);
        }
    }
    printf("\n");
        return 0;
}
