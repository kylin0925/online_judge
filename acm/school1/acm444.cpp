/* @JUDGE_ID: 53xxxx 444 C++ */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char buff[1000],num[3],buffer[1000];
int main(int argc, char* argv[])
{
    int i,j,t;
    while(gets(buff))
    {
          if(!isdigit(buff[0]))
          {
             for(i=strlen(buff)-1;i>=0;i--)
             {
                 t=buff[i];
                 sprintf(num,"%d",t);
                 for(j=strlen(num)-1;j>=0;j--)
                 {
                   printf("%c",num[j]);
                 }
             }
             printf("\n");
          }
          else
          {
             for(j=0,i=strlen(buff)-1;i>=0;i--,j++)
             {
                 buffer[j]=buff[i];
             }
             buffer[j]='\0';
             j=0;
             while(j<strlen(buffer))
             {
                    if(( buffer[j]>='6' && buffer[j]<='9' ))
                    {
                        if( buffer[j]=='6' && buffer[j+1]=='4')
                        {
                          j+=2;
                          continue;
                        }
                        else if(buffer[j]==9)
                        {
                             if(( buffer[j]>='1' && buffer[j]<='6' ))
                             {
                              j+=2;
                              continue;
                             }
                        }
                        else
                        {
                         t=(buffer[j]-'0')*10+buffer[j+1]-'0';
                         printf("%c",t);
                         j+=2;
                        }
                    }
                    else if(buffer[j]=='3'&&buffer[j+1]=='2')
                    {
                          printf(" ");
                          j+=2;
                    }
                    else if(buffer[j]=='3'&&buffer[j+1]=='3')
                    {
                          printf("!");
                          j+=2;
                    }
                    else if(buffer[j]=='4'&&buffer[j+1]=='4')
                    {
                       printf(",");
                          j+=2;
                    }
                    else if(buffer[j]=='4'&&buffer[j+1]=='6')
                    {
                       printf(".");
                          j+=2;
                    }

                    else if(buffer[j]=='5'&&buffer[j+1]=='8')
                    {
                       printf(":");
                          j+=2;
                    }
                    else if(buffer[j]=='5'&&buffer[j+1]=='9')
                    {
                       printf(";");
                          j+=2;
                    }
                    else
                    {
                        t=(buffer[j]-'0')*100+(buffer[j+1]-'0')*10+buffer[j+2]-'0';
                          printf("%c",t);
                          j+=3;
                    }
             }
             printf("\n");
          }
    }
        return 0;
}
