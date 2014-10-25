#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    char in[500];
    int i,f,s,l,seq;
    while(1)
    {
     f=0,s=0,l=0;
     i=0; seq=0;
     gets(in);
     if(!strcmp(in,"e/o/i")) return 0;
     while(in[i]!='/')
     {
      if(in[i]=='a'||in[i]=='e'||in[i]=='i'||in[i]=='o'||in[i]=='u'||in[i]=='y')
      {
         if(!seq)
         {
          f++;
          seq=1;
         }
         else
         {
           seq=0;
         }
      }
      else
      {
           seq=0;
      }
      i++;
     }
     i++;
     seq=0;
     while(in[i]!='/')
     {
      if(in[i]=='a'||in[i]=='e'||in[i]=='i'||in[i]=='o'||in[i]=='u'||in[i]=='y')
      {
        if(!seq)
        {
          s++;
          seq=1;
        }
        else
        {
         seq=0;
        }
      }
      else
      {
           seq=0;
      }
      i++;
     }
     i++;
     seq=0;
     while(i<strlen(in))
     {
      if(in[i]=='a'||in[i]=='e'||in[i]=='i'||in[i]=='o'||in[i]=='u'||in[i]=='y')
      {
         if(!seq)
         {
          l++;
          seq=1;
         }
         else
         {
           seq=0;
         }
      }
      else
      {
           seq=0;
      }
      i++;
     }
      if(f==5&&s==7&&l==5) printf("Y\n");
      else
      {
         if(f==5&&s==7) printf("3\n");
         else if(s==7&&l==5) printf("1\n");
         else if(f==5&&l==5) printf("2\n");
      }
    }
        return 0;
}
