/* @JUDGE_ID: 53xxxx 485 C++ */
#include <stdio.h>
int table[400][100];
int temp[400][100];
void set_a()
{
   int i,j;
   for(i=0;i<400;i++)
   {
        for(j=0;j<100;j++)
        {
          temp[i][j]=0;
        }
   }
}
void print()
{
   int i,j;
   for(i=0;i<400;i++)
   {
    if(!temp[i][0]) break;
    for(j=35;j>=0;j--)
    {
        if(temp[i][j]){printf("%d",temp[i][j]);j--;break;}
    }
    for(;j>=0;j--)
    {
         printf("%04d",temp[i][j]);
    }
     printf("%c",' ');
   }
   printf("\n");
}
void add(int i)
{
   int j,c;
   c=0;
   for(j=0;j<100;j++)
   {
          temp[i][j]=(table[i-1][j]+table[i][j]+c)%10000;
          c=(table[i-1][j]+table[i][j]+c)/10000;
   }
}
int check(int i)
{
    int j;
    if(temp[i][15]>=1)
     return 1;
    else
      return 0;
}
int main(int argc, char **argv)
{
    int i,f,j,k;
    f=1;
    table[0][0]=1;
    table[1][0]=1;

    printf("1 \n");
    printf("1 1 \n");
    while(f)
    {
       for(i=2;f;i++)
       {
        set_a();
        temp[0][0]=1;
         for(j=1;j<i;j++)
         {
           add(j);
           if(check(j)){ f=0;}
         }
        temp[i][0]=1;
        print();
         for(j=0;j<400;j++)
         {
            for(k=0;k<100;k++)
            {
               table[j][k]=temp[j][k];
            }
         }
       }
    }
        return 0;
}
