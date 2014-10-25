/* @JUDGE_ID: 53xxxx 706 C++ */
#include <stdio.h>
#include <string.h>
int f[10]={1,0,1,1,0,1,1,1,1,1};
int s[20]={1,1,0,1,0,1,0,1,1,1,1,0,1,0,0,1,1,1,1,1};
int t[10]={0,0,1,1,1,1,1,0,1,1};
int u[20]={1,1,0,1,1,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1};
int l[10]={1,0,1,1,0,1,1,0,1,1};
int main(int argc, char* argv[])
{
    int len,i,j;
    char num[300],buff[300];
    while(1)
    {
        scanf(" %d %s",&len,&num);
        if(!len && num[0]=='0') break;
        
        for(i=0;i<strlen(num);i++)
        {
           if(f[num[i]-'0'])  memset(buff,'-',len);
           else
             memset(buff,' ',len);
           buff[len]='\0';
           printf(" %s ",buff);
           if(i<strlen(num)-1)
            printf("%c",' ');
        }
        printf("\n");
        for(j=0;j<len;j++){
         for(i=0;i<strlen(num);i++)
         {
           if((s[(num[i]-'0')*2]))
           {
             printf("|");
             memset(buff,' ',len);
             buff[len]='\0';
             printf("%s",buff);
           }
           else
           {
             printf("%c",' ');
             memset(buff,' ',len);
             buff[len+1]='\0';
             printf("%s",buff);
           }

           if(s[(num[i]-'0')*2+1])
           {
              printf("|");
           }
           else
           {
              printf("%c",' ');
           }
           if(i<strlen(num)-1)
            printf("%c",' ');
         }
         if(j<len-1)
          printf("\n");
        }

        printf("\n");
        for(i=0;i<strlen(num);i++)
        {
           if(t[num[i]-'0'])
           {
             memset(buff,'-',len);
           }
           else
           {
             memset(buff,' ',len);
           }
           printf(" %s ",buff);
           if(i<strlen(num)-1)
            printf("%c",' ');
        }/*third end*/
        printf("\n");
        for(j=0;j<len;j++)
        {
          for(i=0;i<strlen(num);i++)
          {
            if(u[(num[i]-'0')*2])
            {

              printf("|");
              memset(buff,' ',len);
              buff[len]='\0';
              printf("%s",buff);
            }
            else
            {
              printf("%c",' ');
              memset(buff,' ',len);
              buff[len]='\0';
              printf("%s",buff);
            }
            if(u[(num[i]-'0')*2+1])
            {
               printf("|");
            }
            else
            {
               printf("%c",' ');
            }
            if(i<strlen(num)-1)
             printf("%c",' ');
          }
          if(j<len-1)
           printf("\n");
         }

           printf("\n");

         for(i=0;i<strlen(num);i++)
         {
            if(l[num[i]-'0'])
            {
              memset(buff,'-',len);
            }
            else
            {
              memset(buff,' ',len);
            }
            buff[len]='\0';
            printf(" %s ",buff);
            if(i<strlen(num)-1)
             printf("%c",' ');
          }
           printf("\n\n");

    }
        return 0;
}
