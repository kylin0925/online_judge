/* @JUDGE_ID: 53xxxx  338 C++ */
#include <stdio.h>
#include <string.h>
int main()
{
        long double x,y,ans,tmp,tt;
        char cr[20],cx[12],cy[12],sp=' ';
        int i,j,lx,ly,lr,maxl,ma,spc;
        while(scanf("%Lf",&x)==1)
        {
            if(x==0){
                     if(scanf("%Lf",&tt)==EOF) break;
                     else
                     {
                       y=tt;
                    }
            }
            else
            {
                  scanf("%Lf",&y);
            }
            ans=x*y;
            sprintf(cx,"%.0Lf",x);
            sprintf(cy,"%.0Lf",y);
            sprintf(cr,"%.0Lf",ans);
            lx=strlen(cx);
            ly=strlen(cy);
            lr=strlen(cr);
            if(lx>ly) maxl=lx;
            else
              maxl=ly;
            spc=lr-maxl;

            if((lr==lx)||(lr==ly))
            {
             if(lr-lx==0) printf("%.0Lf\n",x);
             else
              printf("%*c%.0Lf\n",maxl-lx,' ',x);
             if(lr-ly==0)  printf("%.0Lf\n",y);
             else
              printf("%*c%.0Lf\n",maxl-ly,' ',y);
            }
            else
            {
             printf("%*c%.0Lf\n",spc+(maxl-lx),' ',x);
             printf("%*c%.0Lf\n",spc+(maxl-ly),' ',y);
            }
            if(spc>0)
             printf("%*c",spc,' ');
            for(i=0;i<maxl;i++) printf("-");
            printf("\n");
            if(maxl>1)
            {
               for(j=ly-1,i=0;j>0;i++,j--)
               {
                     tt=(cy[j]-'0')*x;
                     if(tt!=0)
                      printf("%*c%.0Lf\n",spc-i,' ',tt);
               }
               printf("%.0Lf\n",(cy[0]-'0')*x);
               for(i=0;i<lr;i++)printf("-");
               printf("\n%.0Lf\n",ans);
            }
            else
            {
               printf("%.0Lf\n",ans);
            }
         }

        return 0;
}

