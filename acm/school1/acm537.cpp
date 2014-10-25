#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    char buff[500];
    char *to,*tmp;
    int p,i,u,c,n,ss;
    char f,sec;
    scanf("%d",&n);
    for(;n>0;n--)
    {
      gets(buff);
      to=strtok(buff," ");
      c=0;ss=1
      while(to!=NULL)
      {
          to=strtok(NULL," ");
          if(to[0]=='U')
          {

                tmp=strtok(to,"=");
                tmp=strtok(NULL,"V");
                sscanf(tmp,"%d",&u);
                if(ss)
                {
                   f='U';
                   ss=0;
                }
                else
                {
                   if(f=='P') printf("%d",p/u);
                   else  if(f=='I'){ printf("%d",u*i);}
                }
          }
          else if(to[0]=='P')
          {
                tmp=strtok(to,"=");
                tmp=strtok(NULL,"V");
                sscanf(tmp,"%d",&u);
                if(ss)
                {
                   f='P';
                   ss=0;
                }
                else
                {
                   if(f=='I') u=p/i;
                   else  if(f=='I') printf("%d",u*i);
                }
          }
          else if(to[0]=='I')
          {
                tmp=strtok(to,"=");
                tmp=strtok(NULL,"V");
                sscanf(tmp,"%d",&u);
                if(ss)
                {
                   f='P';
                   ss=0;
                }
                else
                {
                   if(f=='I') u=p/i;
                   else  if(f=='I') printf("%d",u*i);
                }
          }
        }
    }
        return 0;
}
