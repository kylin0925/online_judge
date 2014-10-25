#include <stdio.h>
#include <string.h>
char s1[550];
char s2[550];
int d[550][550],i,j;
int main(int argc, char* argv[])
{
    FILE *fp,*fpo;
    char buff[1000];

    double len;
    double l;
    fp=fopen("pd.dat","r");
    fpo=fopen("pdout.dat","w");
    fgets(buff,600,fp);
    sscanf(buff,"%[^\n]s",&buff);
    strcpy(s1,buff);
    while(1)
    {
       fgets(buff,600,fp);
       if(buff[0]=='\n') break;
       sscanf(buff,"%[^\n]s",&buff);
       strcat(s1,buff);
    }
     fgets(buff,600,fp);
     sscanf(buff,"%[^\n]s",&buff);
     strcpy(s2,buff);
    while(fgets(buff,600,fp))
    {

       if(buff[0]=='\n') break;
       sscanf(buff,"%[^\n]s",&buff);
       strcat(s2,buff);
    }

   
    for(i=0;i<=strlen(s2);i++) d[i][0]=0;
    for(i=0;i<=strlen(s1);i++) d[0][i]=0;
    for(i=1;i<=strlen(s1);i++)
    {
        for(j=1;j<=strlen(s2);j++)
        {
             if(s1[i-1]==s2[j-1]) d[i][j]=d[i-1][j-1]+1;
             else if(d[i][j-1]>d[i-1][j]) d[i][j]=d[i][j-1];
             else
                  d[i][j]=d[i-1][j];
        }
    }
    len=d[strlen(s1)][strlen(s2)];
    l=(len/strlen(s2))*100+0.5;
    printf("%.0f / %d = %.0f %\n",len,strlen(s1),l);
        return 0;
}
