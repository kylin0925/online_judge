#include <stdio.h>
#include <string.h>
void rv(char a[])
{
   int i,len;
   char t;
   len=strlen(a);
   for(i=0;i<len/2;i++)
   {
       t=a[i];
       a[i]=a[len-i-1];
       a[len-i-1]=t;
   }
}
int main()
{
    char cbuf[10];
    char buf[10000];
    int   i,j,k;
    while(gets(buf))
    {
       i=0;
       while(buf[i]!='\0')
       {
          j=0;
          for(k=0;k<10;k++){cbuf[k]='\0';}
          while(buf[i]>='a'&&buf[i]<='z'||buf[i]>='A'&&buf[i]<='Z')
          {
             cbuf[j++]=buf[i++];
          }

           cbuf[j]='\0';
           rv(cbuf);
           printf("%s",cbuf);
           while(buf[i++]==' ') printf(" ");
           i--;
       }
        printf("\n");
       for(k=0;k<10000;k++){buf[k]='\0';}

    }
        return 0;
}
/* END_OF_SOURCE_CODE */


