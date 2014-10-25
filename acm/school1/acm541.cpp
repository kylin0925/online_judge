/* @JUDGE_ID: 53xxxx 541 C++ */
#include <stdio.h>
int mat[150][150];
int n;
int iseven(void)
{
      int i,j,t,even=0,odd=0;
      for(i=0;i<n;i++)
      {
             for(j=0;j<n;j++)
             {
                  t+=mat[i][j];
             }
             if(t%2==1)
             {
                odd++;
             }
             else
             {
                even++;
             }
             t=0;
         }

         for(i=0;i<n;i++)
         {
             for(j=0;j<n;j++)
             {
                  t+=mat[j][i];
             }
             if(t%2==1){odd++;}
             else
             {even++;}
             t=0;
         }
         if(even==2*n ||odd==2*n){return 2;}
         else if(even>odd){return 1;}
         else
         { return 0; }
}
int main(int argc, char* argv[])
{
     int i,j,ok=0,d;
     while(1)
     {
         scanf("%d",&n);
         if(n==0) break;
         d=0;
         for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
               scanf("%d",&mat[i][j]);
            }
         }
         if(iseven()==1)
         {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    mat[i][j]=!mat[i][j];
                    d=iseven();
                    mat[i][j]=!mat[i][j];
                    if(d==2){ ok=1;break;}
                }
                if(d==2) break;
            }
            if(d==2)
            {
               printf("Change bit(%d,%d)\n",i+1,j+1);
            }
            else
            {
              printf("Corrupt\n");
            }
         }
         else if(iseven()==2)
         {
              printf("ok\n");
         }
         
     }
        return 0;
}
