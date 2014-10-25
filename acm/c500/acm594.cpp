/* @JUDGE_ID: 53xxxx  594 C++ */
#include <stdio.h>
#include <string.h>
int main()
{
     char buffer[9],b[3]="ab";
     long int in,i,o,o1;
     while(scanf("%ld",&in)==1)
     {
           o1=0;
           o=0;
           sprintf(buffer,"%08X",in);
           for(i=strlen(buffer)-2;i>=0;i=i-2)
           {
               b[0]=buffer[i];
               b[1]=buffer[i+1];
               sscanf(b,"%X",&o1);
               o=o<<8;
               o+=o1;
           }

            printf("%ld converts to %ld\n",in,o);                       
     }
        return 0;
}
