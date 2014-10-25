/* @JUDGE_ID: 53xxxx 119 C++ */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char name[300][500];
int money[300];
int n;
char buff[10000],tmp[50],*tmp1;
int i,j,x,y,wtogimon,gn;
int main(int argc, char* argv[])
{
   while(scanf("%d",&n)==1)
   {
       for(i=0;i<300;i++) money[i]=0;
       for(i=0;i<n;i++)
       {
        scanf("%s",&name[i]);
       }
       scanf("\n");
       for(i=0;i<n;i++)
       {
         gets(buff);
         tmp1=strtok(buff," ");
         for(j=0;j<n;j++)
         {
            if(!strcmp(name[j],tmp1)) break;
         }
         tmp1=strtok(NULL," ");
         sscanf(tmp1,"%d",&wtogimon);

         tmp1=strtok(NULL," ");
         sscanf(tmp1,"%d",&gn);

         if(gn==0) continue;
         money[j]=money[j]-wtogimon+wtogimon%gn;
         wtogimon/=gn;

          for(x=0;x<gn;x++)
          {
            tmp1=strtok(NULL," ");
            for(y=0;y<n;y++)
            {
                  if(!strcmp(name[y],tmp1))
                  {
                     money[y]+=wtogimon;
                  }
               }
           }
        }
        for(i=0;i<n;i++)
        {
          printf("%s %d\n",name[i],money[i]);
        }
        printf("\n");
   }

        return 0;
}
