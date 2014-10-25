/* @JUDGE_ID: 53xxxx 128 C++ */
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
    char in[2000],tmp[10];
    unsigned long v;
    int i;
    while(gets(in))
    {
      v=0;
      if(in[0]=='#'){ return 0;break;}
      for(i=0;i<strlen(in);i++)
      {
          v=v<<8;
          v+=in[i];
          v%=34943;
      }
      v=v<<16;
      v%=34943;
      if(v) v=34943-v;
      sprintf(tmp,"%04X",v);
      printf("%c%c ",tmp[0],tmp[1]);
      printf("%c%c\n",tmp[2],tmp[3]);
    }
        return 0;
}
