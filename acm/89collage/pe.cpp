#include <stdio.h>
#include <string.h>
char *var[100];
char buff[200];
char *tmp;
double var_val[100];
int main(int argc, char* argv[])
{
    int i,j,n,s=0;
    n=0;
    while(gets(buff))
    {
      s=0;
       if(buff[0]=='q') break;
       else if(buff[0]=='=')
       {
          tmp=strtok(buff," ");
          tmp=strtok(NULL," ");
          strcpy(var[n],tmp);
          tmp=strtok(NULL," ");
          for(i=0;i<strlen(tmp);i++)
          {
            if(tmp[i]=='+' || tmp[i]=='-' || tmp[i]=='*' ||tmp[i]=='/')
            s=1;
          }
          if(!s)
          {
           for(i=0;i<n;i++)
           {
            if(!strcmp(var[i],tmp)) break;
           }
            if(i==n)
              sscanf(tmp,"%d",&var_val[n]);
            else
            {
               strcpy(var[n],tmp);
               var_val[n]=var_val[i];
            }
          }
          else
          {
             tmp=strtok
          }
       }
       else if(buff[0]=='p')
       {
       }
       else if(buff[0]=='d')
       {
       }
       else
       {
       }
    }
        return 0;
}
