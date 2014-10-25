#include <stdio.h>
#include <string.h>
int pstack[150];
int find(int obj)
{
    int i;
    for(i=0;i<obj;i++)
    {
       if(s[i]!=obj) return i;
    }
}
int swap(int p)
{
   int t,i;
   for(i=0;i*2<p;i++)
   {
       t=pstack[p-i];
       pstack[i]=pstack[p-i];
       pstack[p-i]=t;
   }
}
int main(int argc, char* argv[])
{
    char p[500],*tmp;
    int pstack[150],i,nowmax,pos;
    while(gets(p))
    {
         tmp=strtok(p," ");
         i=0;
         sscanf(tmp,"%d",&pstack[i++]);
         while(tmp!=NULL)
         {
              tmp=strtok(NULL," ");
             if(tmp!=NULL)
              sscanf(tmp,"%d",&pstack[i++]);
         }
         nowmax=i;
         while(nowmax>1)
         {
              pos=find(nowmax);
              swap(pos);
              printf("%d",pos);
              nowmax--;
         } 
    }
              return 0;
}
