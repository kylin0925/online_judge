/* @JUDGE_ID:6709ZK  118 C++ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lostt;
int right,top,len;
int x,y,see;
char command[120];
int lost[600][600][40];

void turn(char tu)
{
   int bx,by;
   bx=x;
   by=y;

   if(tu=='R')
   {
     see++;
     if(see>4)
     {
     see=1;
     }
   }
   else if(tu=='L')
   {
     see--;
     if(see==0)
     {
     see=4;
     }
   }
   else if(tu=='F')
   {
      if(lost[bx][by][see]==0)
      {
      if(see==1)
      {
        y=y+1;
      }
      else if(see==2)
      {
        x=x+1;
      }
      else if(see==3)
      {
        y=y-1;
      }
      else if(see==4)
      {
        x=x-1;
      }

      if(x<0||y<0||x>right||y>top)
      {

         if(by+1>top)
         lost[bx][by][1]=1;
         if(bx+1>right)
         lost[bx][by][2]=1;
         if(by-1<0)
         lost[bx][by][3]=1;
         if(bx-1<0)         
         lost[bx][by][4]=1;
         lostt=1;
      }

      }
   }
if(lostt==1)
{
x=bx;
y=by;
}

}
void main()
{


    int i,j,k,ii;
    char seec;
    char seecs[7];
    seecs[1]='N';
    seecs[2]='E';
    seecs[3]='S';
    seecs[4]='W';


    scanf("%d %d",&right,&top);
    len=0;


    while(scanf("%d %d %c",&x,&y,&seec)==3)
    {
       scanf("%s",command);
       if(seec=='N')
       see=1;
       else if(seec=='E')
       see=2;                                            
       else if(seec=='S')
       see=3;
       else if(seec=='W')
       see=4;

       lostt=0;
       for(i=0;i<strlen(command);i++)
       {
          if(lostt==0)                          
          {                     
          turn(command[i]);
          }

       }

       printf("%d %d %c",x,y,seecs[see]);
       if(lostt==1)
       printf(" LOST\n");
       else
       printf("\n");

    }

}

