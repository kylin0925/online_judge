#include <stdio.h>
#include <math.h>
char down[32],up[32];
int main()
{
    char  a;
    int con,fd=1,fu=0;
    long double i;
    gets(down);
    gets(up);
    i=4;
    con=0;
    while(scanf("%c",&a)==1)
    {
         //fd=1,fu=0;
         if(a=='\n')
         {
          fd=1,fu=0;
          printf("\n");
         }
         else
         {
               con+=(a-'0')*(pow(2.0,i)+0.00001);
               i--;
               if(i==-1)
               {
                  //con+=a-'0';
                  i=4;
                  if(con==31){ fd=0,fu=1,con=0;}
                  else if(con==27){ fd=1,fu=0,con=0;}
                  else if(fd)
                  {

                      printf("%c",down[con]);
                      con=0;
                  }
                  else
                  {
                      printf("%c",up[con]);
                      con=0;
                  }
                }
         }
    }
        return 0;
}
