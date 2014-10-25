/* @JUDGE_ID: 53xxxx 739 C++ */
#include <stdio.h>
#include <string.h>
int end(char c)
{
   if(c=='B'|| c=='P' || c=='F'|| c=='V')
   {
       return 1;
   }
   else if(c=='C'|| c=='S'|| c=='K'|| c=='G'||c=='J'||c=='Q'||c=='X'||c=='Z')
   {
      return 2;
   }
   else if(c=='D'||c=='T')
   {
      return 3;
   }
   else if(c=='L')
   {
      return 4;
   }
   else if(c=='M'||c=='N')
   {
      return 5;
   }
   else if(c=='R')
   {
      return 6;
   }
   else
   {return 0;}
}
void main()
{
     char na[50],c,tmp[50];
     int i,j,t,nde[50],tn[5];
     int f=1,len;

     printf("%9cNAME%22cSOUNDEX CODE\n",' ',' ');

     while(scanf("%s",&na)==1)
     {
        for(i=0;i<50;i++){nde[i]=0;}

        for(i=0;i<strlen(na);i++)
        {

           nde[i]=end(na[i]);
        }
        for(j=strlen(na)-2;j>=0;j--)
        {
           if(nde[j]==nde[j+1]) nde[j+1]=0;
        }
         nde[0]=0;
        for(j=0,i=0;j<strlen(na);j++)
        {
            if(nde[j]!=0)
            {
               tn[i++]=nde[j];
            }
        }
        tn[i]=0,tn[i+1]=0,tn[i+2]=0;
        printf("         %s",na);
        printf("%*c%c",25-strlen(na)+2,' ',na[0]);
        for(i=0;i<3;i++) printf("%d",tn[i]);
        printf("\n");
     }
     printf("%20cEND OF OUTPUT\n",' ');

}
