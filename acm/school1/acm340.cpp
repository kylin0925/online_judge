/* @JUDGE_ID:53xxxx 340 C++ */
#include <stdio.h>
void main()
{
     int a,b,n,i,j;
     int sc[1100],g[1100];
     int ng[1100],nsc[1100],ter,game=1,tr=1;
     while(tr)
     {
         for(i=0;i<1100;i++){g[i]=sc[i]=0;}
         for(i=0;i<1100;i++){ng[i]=nsc[i]=0;}
         scanf("%d",&n);
         if(n==0) break;
         a=0,b=0,ter=0;
         for(i=1;i<=n;i++)
         {
           scanf("%d",&sc[i]);
         }
         printf("Game %d:\n",game);
         while(!ter)
         {
                 for(i=0;i<1100;i++){ng[i]=nsc[i]=0;}
                 a=0,b=0;
                 for(i=1;i<=n;i++)
                 {
                    scanf("%d",&g[i]);
                 }
                 if(g[1]==0){ ter=1;}
                 if(!ter)
                 {

                    for(i=1;i<=n;i++)
                    {
                        if(sc[i]==g[i])
                        {
                          a++;
                          nsc[i]=1;
                          ng[i]=1;
                        }
                    }
                    for(i=1;i<=n;i++)
                    {
                        for(j=1;j<=n;j++)
                        {
                            if(!ng[i]&&!nsc[j])
                            {
                               if(g[i]==sc[j])
                               {
                                 b++;
                                 ng[i]=1;
                                 nsc[j]=1;
                               }
                            }
                         }
                     }

                     printf("    (%d,%d)\n",a,b);
                  }
         }
         game++;
         ter=0;
      }
}
