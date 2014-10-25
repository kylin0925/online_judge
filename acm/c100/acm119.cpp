/* @JUDGE_ID: 53xxxx 119 C++ */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char name[300][500];
int   money[300];
int n;
char buff[2000],tmp[50],*tmp1,*tmpmon,*tn;
int f=0,s=0,i,j,wtogimon,gn,gtoi;
int main(int argc, char* argv[])
{
   while(gets(buff))
   {
        if(buff[0]=='\0') continue;
        if(isdigit(buff[0])&&!s)
        {
           f++;
           sscanf(buff,"%d",&n);
           s=1;
        }
        else if(isdigit(buff[0])&&s)
        {
           for(i=0;i<n;i++)
           {
               printf("%s %d\n",name[i],money[i]);
           }
           printf("\n");
           for(i=0;i<n;i++)
           {
              strcpy(name[i]," ");
              money[i]=0;
           }
           sscanf(buff,"%d",&n);
           f=1,s=1;
        }
        else if(f==1)
        {
            tmp1=strtok(buff," ");
            strcpy(name[0],tmp1);
            for(i=1;i<n;i++)
            {
               tmp1=strtok(NULL," ");
               strcpy(name[i],tmp1);
            }
            f++;
        }
        else
        {
           tmp1=strtok(buff," ");
           tmpmon=strtok(NULL," ");
           sscanf(tmpmon,"%d",&wtogimon);
           for(i=0;i<n;i++)
           {
              if(!strcmp(name[i],tmp1))
              {
                  money[i]-=wtogimon;
                  break;
              }
           }

           tn=strtok(NULL," ");
           sscanf(tn,"%d",&gn);
           if(gn==0) continue;
           money[i]+=wtogimon%gn;
           wtogimon/=gn;
           for(i=0;i<gn;i++)
           {
               tmp1=strtok(NULL," ");
               for(j=0;j<n;j++)
               {
                  if(!strcmp(name[j],tmp1))
                  {
                     money[j]+=wtogimon;
                  }
               }
           }
        }
   }
   for(i=0;i<n;i++)
   {
        printf("%s %d\n",name[i],money[i]);
   }
   printf("\n");
        return 0;
}
