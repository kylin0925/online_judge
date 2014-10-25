/* @JUDGE_ID: 53xxxx 588 C++ */
#include <stdio.h>
int vx[200],vy[200];
int resu[200][10];
int iscol(int x1,int x2){return  (x1==x2);}
int main(int argc, char* argv[])
{
    int n,i,j;
    int tx,ty,c=1,f=0;
    while(1)
    {
       for(i=0;i<200;i++)for(j=0;j<10;j++){resu[i][j]=0;}
       scanf("%d",&n);
       if(!n) break;
       f=0;
       for(i=0;i<n;i++)
       {
        scanf("%d %d",&vx[i],&vy[i]);
       }
       if(iscol(vx[0],vx[1]))
       {
           if(vy[1]>vy[0])
           {
             resu[0][0]=4;
             resu[0][1]=0;resu[0][2]=2;resu[0][3]=vx[0];
           }
           else
           {
             resu[0][0]=3;
             resu[0][1]=0;resu[0][2]=1;resu[0][3]=vx[0];
           }
       }
       else
       {
           if(vx[1]>vx[0])
           {
             resu[0][0]=2;
             resu[0][1]=1; resu[0][2]=1; resu[0][3]=vy[0];
           }
           else
           {
             resu[0][0]=1;
             resu[0][1]=1; resu[0][2]=2; resu[0][3]=vy[0];
           }
       }
       vx[n]=vx[0],vy[n]=vy[0];
       for(i=2;i<=n;i++)
       {
        if(iscol(vx[i-1],vx[i]))
        {
          if(resu[i-2][0]==1)
          {
           if((vy[i]<vy[i-2]&&vx[i]<vx[i-2])||(vy[i]>vy[i-2]&&vx[i]>vx[i-2]))
           {
              resu[i-1][0]=3;
              resu[i-1][1]=0;resu[i-1][2]=1;resu[i-1][3]=vx[i];
           }
           else
           {
             resu[i-1][0]=4;
             resu[i-1][1]=0;resu[i-1][2]=2;resu[i-1][3]=vx[i];
           }
          }
          else
          {
            if((vy[i]<vy[i-2]&&vx[i]>vx[i-2])||(vy[i]>vy[i-2]&&vx[i]<vx[i-2]))
            {
             resu[i-1][0]=3;
             resu[i-1][1]=0;resu[i-1][2]=1;resu[i-1][3]=vx[i];
            }
            else
            {
             resu[i-1][0]=4;
             resu[i-1][1]=0;resu[i-1][2]=2;resu[i-1][3]=vx[i];
            }
           }
        }
        else
        {
           if(resu[i-2][0]==3)
           {
            if((vy[i]<vy[i-2]&&vx[i]>vx[i-1])||(vy[i]>vy[i-2]&&vx[i]<vx[i-1]))
            {
               resu[i-1][0]=2;
               resu[i-1][1]=1;resu[i-1][2]=1;resu[i-1][3]=vy[i];
            }
            else
            {
              resu[i-1][0]=1;
              resu[i-1][1]=1;resu[i-1][2]=2;resu[i-1][3]=vy[i];
            }
           }
           else
           {
            if((vy[i]<vy[i-2]&&vx[i]<vx[i-1])||(vy[i]>vy[i-2]&&vx[i]>vx[i-1]))
            {
              resu[i-1][0]=2;
              resu[i-1][1]=1;resu[i-1][2]=1;resu[i-1][3]=vy[i];
            }
            else
            {
               resu[i-1][0]=1;
               resu[i-1][1]=1;resu[i-1][2]=2;resu[i-1][3]=vy[i];
            }
           }
        }
       }
       for(i=0;i<n;i++)
       {
           for(j=i;j<n;j++)
           {
              if(resu[i][0]==1)
              {
                  if(resu[j][0]==2)
                  {
                     if(resu[i][3]>resu[j][3])
                     {
                       f=-1;
                       break;
                     }
                  }
              }
              else if(resu[i][0]==2)
              {
                  if(resu[j][0]==1)
                  {
                     if(resu[j][3]>resu[i][3])
                     {
                       f=-1;break;
                     }
                  }

              }
              else if(resu[i][0]==3)
              {
                  if(resu[j][0]==4)
                  {
                     if(resu[i][3]<resu[j][3])
                     {
                       f=-1; break;
                     }
                  }

              }
              else if(resu[i][0]==4)
              {
                  if(resu[j][0]==3)
                  {
                     if(resu[i][3]>resu[j][3])
                     {
                       f=-1;    break;
                     }
                  }

              }
           }
           if(f==-1) break;
       }
       if(f!=-1)
       {
        printf("Floor #%d\n",c++);
        printf("Surveillance is possible.\n");
       }
       else
       {
         printf("Floor #%d\n",c++);
         printf("Surveillance is impossible.\n");
       }
    }
        return 0;
}
