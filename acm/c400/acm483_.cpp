/* @JUDGE_ID: 53xxxx 483 C++ */
#include <stdio.h>
#include <string.h>
char cbuf[1000];
void rv()
{
   int i,len;
   char t;
   len=strlen(cbuf);
   for(i=0;i<len/2;i++)
   {
       t=cbuf[i];
       cbuf[i]=cbuf[len-i-1];
       cbuf[len-i-1]=t;
   }
}
int main()
{

    char buf[1000];
    int   i,j,k;
    while(gets(buf))
    {
       i=0;
       while(i<strlen(buf))
       {
          j=0;
          //for(k=0;k<1000;k++){cbuf[k]='\0';}
          while(buf[i]!=' ')
          {
             cbuf[j++]=buf[i++];
          }

           cbuf[j]='\0';
           rv();
           printf("%s",cbuf);
           while(buf[i++]==' ') printf(" ");
           i--;
       }
        printf("\n");
       

    }
        return 0;
}



