#include <stdio.h>
#include <string.h>
int  anum[10][7]={{1,1,1,0,1,1,1},   //0
                  {0,0,1,0,0,1,0},   //1
                  {1,0,1,1,1,0,1},   //2
                  {1,0,1,1,0,1,1},   //3
                  {0,1,1,1,0,1,0},   //4
                  {1,1,0,1,0,1,1},   //5
                  {0,1,0,1,1,1,1},   //6
                  {1,0,1,0,0,1,0},   //7
                  {1,1,1,1,1,1,1},   //8
                  {1,1,1,1,0,1,0},   //9
                 };
int main()
{
    int l,i,j,x,cnum;
    char num[15];
    while(scanf("%d %s",&l,&num)==2)
    {
          i=0;
          while(i<7)
          {

              for(j=0;j<strlen(num);j++)
              {
                  cnum=strlen(num);
                  if(anum[i][j]==1)
                  {
                     if(j==1 ||j==2 || j==4 || j==5)
                     {
                        printf("|");
                        cnum--
                     }
                     else
                     {
                        for(x=0;x<cnum;x++)
                        {
                          printf("-");
                        }
                        cnum=0;
                     }
                  }
              }
          }
    }
        return 0;
}
