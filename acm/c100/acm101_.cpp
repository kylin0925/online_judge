#include <stdio.h>
int top[25];
int arrn[25][25];
int topn[25];
void sov(char c1[],int a,char c2[],int b)
{
     int i;
     if(c1[0]=='m')
     {
        if(c2[1]=='n')
        {
            if(top[b]!=b)
            {
               for(i=1;arrn[b][i]!=-1;i++)
               {
                  arrn[b][i]=top[i];
               }
            }
            else
            {
               arrn[b][1]=a;
            }
        }
        else
        {
        }
     }
     else
     {
         if(c2[1]=='n')
         else
         {
         }
     }
}
int main()
{
   int  n,i,j;
   int  m1,m2;
   char command1[4],command2[4];
   for(i=0;i<25;i++)
   {
       arrn[i][0]=i;
       top[i]=i;
       topn[i]=1;
       for(j=1;j<25;j++)
       {
           arrn[i][j]=-1;
       }
   }
   scanf("%d",&n);
   while(1)
   {
     scanf("%s",&command1);
     if(command1[0]=='q') break;
     scanf("%d %s %d",&m1,&command2,&m2);
     sov(command1,m1,command2,m2);
   }
   for(i=0;i<n;i++)
   {
       printf("%d:",i);
       for(j=0;arrn[i][j]!=-1;j++)
       {
           printf("%2d",arrn[i][j])
       }
        printf("\n");
   }
        return 0;
}
