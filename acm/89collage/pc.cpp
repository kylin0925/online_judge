#include <stdio.h>
#include <string.h>
int ri[4];
int map[100][100];
int main(int argc, char* argv[])
{
    char buff[300];
    char *ex;
    int i,j,ins,insi,c,clock;
    while(gets(buff))
    {
      if(!strcmp(buff,"END"))break;
      sscanf(strtok(buff," "),"%d",&ri[0]);
      sscanf(strtok(NULL," "),"%d",&ri[1]);
      sscanf(strtok(NULL," "),"%d",&ri[2]);
      sscanf(strtok(NULL," "),"%d",&ri[3]);
      ins=0;
      while(1)
      {
        gets(buff);

        ex=strtok(buff," ");
        if(!strcmp(buff,"ADD"))
        {
           map[ins][0]=1;
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins][1]=ex[i+1]-'0';
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins][2]=ex[i+1]-'0';
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins++][3]=ex[i+1]-'0';
        }
        else if(!strcmp(buff,"ADDi"))
        {
           map[ins][0]=2;
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins][1]=ex[i+1]-'0';
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins][2]=ex[i+1]-'0';
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           if(i>0)
           {
            for(;i<strlen(ex);i++)
            {
             ex[i-1]=ex[i];
            }
            ex[i-1]='\0';
           }
           sscanf(ex,"%d",&map[ins++][3]);

        }
        else if(!strcmp(buff,"SUB"))
        {
           map[ins][0]=3;
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins][1]=ex[i+1]-'0';
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins][2]=ex[i+1]-'0';
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins++][3]=ex[i+1]-'0';

        }
        else if(!strcmp(buff,"BNE"))
        {
           map[ins][0]=4;
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins][1]=ex[i+1]-'0';
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           map[ins][2]=ex[i+1]-'0';
           ex=strtok(NULL,",");
           for(i=0;i<strlen(ex);i++){if(ex[i]!=' ') break;}
           if(i>0)
           {
            for(;i<strlen(ex);i++)
            {
             ex[i-1]=ex[i];
            }
            ex[i-1]='\0';
           }
           sscanf(ex,"%d",&map[ins++][3]);

        }
        else if(!strcmp(buff,"HALT")){map[ins++][0]=5; break;}
      }
      for(i=0;i<ins;i++)
      {
          for(j=0;j<10;j++)
          {
            printf("%d ",map[i][j]);
          }
          printf("\n");
      }
      insi=ins;
      c=clock=ins=0;
      while(1)
      {
         if(map[c][0]==1)
         {
            ri[map[c][1]]=ri[map[c][2]]+ri[map[c][3]];
            c++;
            ins++;
            clock++;
         }
         else if(map[c][0]==2)
         {
           ri[map[c][1]]=ri[map[c][2]]+map[c][3];
           c++;
           ins++;
           clock++;
         }
         else if(map[c][0]==3)
         {
          ri[map[c][1]]=ri[map[c][2]]-ri[map[c][3]];
          c++;
          ins++;
          clock++;
         }
         else if(map[c][0]==4)
         {
              if(ri[map[c][1]]==ri[map[c][2]])
              {
                c++;
                ins++;
              }
              else
              {
                 c+=map[c][3];
                 c=c%insi;
                 ins++;
              }
              clock+=2;
         }
         else if(map[c][0]==5)
         {
             ins++;
             clock++;
             break;
         }
      }
      printf("%d\n%d\n",ins,clock);

    }
        return 0;
}
