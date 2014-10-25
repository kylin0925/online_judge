/* @JUDGE_ID: 53xxxx 409 C++ */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char  key[30][100],ex[40][300];
char  tmps[300];

int isthesame(char tmp2[],char tmp1[])
{
    int i,len;
    char a[100],b[100];
    strcpy(b,tmp1);
    strcpy(a,tmp2);
    if(strlen(a)!=strlen(b))
    {
       return 0;
    }
    else
    {
     len=strlen(a);
     for(i=0;i<len;i++)
     {
        a[i]=toupper(a[i]);
        b[i]=toupper(b[i]);
     }
     for(i=0;i<len;i++)
     {
        if(a[i]!=b[i]) return 0;
     }
     return 1;
    }
}
int find(char fk[],int k)
{
    int i;
    for(i=1;i<=k;i++)
    {
        if(isthesame(fk,key[i])) return 1;
    }
    return 0;
}
int comp(int n,int k)
{
    int c=0;
    char *tmp;
    tmp=strtok(tmps," ");
    if(find(tmp,k)) c++;
    while(tmp!=NULL)
    {
        tmp=strtok(NULL," ");
        if(tmp!=NULL){ if(find(tmp,k)) c++;}
    }
    return c;
}
int main(int argc, char* argv[])
{
    int   k,e,i,j,m,max,p,c=1;
    int   mm[100]={0};
    while(scanf("%d %d",&k,&e)==2)
    {
         max=-1;
         for(i=0;i<=k;i++)
         {
            gets(key[i]);
         }

         for(i=0;i<e;i++)
         {
            gets(ex[i]);
            strcpy(tmps,ex[i]);
            for(j=0;j<strlen(tmps);j++)
            {
              if(!isalpha(tmps[j])&&!isdigit(tmps[j]))
              {
                  tmps[j]=' ';
              }
            }
            m=comp(i,k);
            if(m>max){for(j=0;j<100;mm[j]=0,j++) max=m;mm[i]=1;}
            else if(m==max){max=m;mm[i]=1;}
         }
         printf("Excuse Set #%d\n",c++);
         for(i=0;i<100;i++)
         {
           if(mm[i]){
             printf("%s\n",ex[i]);
            }
         }
         printf("\n");
         for(i=0;i<100;mm[i]=0,i++);
    }
        return 0;
}
