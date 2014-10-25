/* @JUDGE_ID: 53xxxx  338 C++ */
#include <stdio.h>
#include <string.h>
int main()
{
        long double x,y,ans,tmp,tt;
        char cr[20],cx[12],cy[12],sp=' ';
        int i,j,len1,len2,lr,m,mi,maxl;
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
            lr=strlen(cr);
            len1=strlen(cx);
            len2=strlen(cy);
            (len1>len2)?m=len1:m=len2;
            (lr>m)?maxl=lr:maxl=m;
            (len1>len2)?mi=len2:mi=len1;
            printf("%*s\n",maxl,cx);
            printf("%*s\n",maxl,cy);

            (len1>len2)?m=len1:m=len2;
            (len1>len2)?mi=len2:mi=len1;
            if((len1>1) && (len2>1))
            {
              printf("%*c",lr-m,sp);
              for(i=0;i<m;i++) printf("-");
              printf("\n");
                    for(i=len2-1,j=0;i>=0;i--,j++)
                    {
                        tmp=x*(cy[len2-j-1]-'0');
                        if(tmp!=0)
                         printf("%*.0Lf\n",lr-j,tmp);
                    }
           }
           if(maxl>1)
           {
              for(i=0;i<maxl;i++) printf("-");
           }else {
              printf("-");
           }
              printf("\n%*.0Lf\n\n",maxl,ans);

         }

        return 0;
}

