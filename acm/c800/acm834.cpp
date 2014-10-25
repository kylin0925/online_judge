/* @JUDGE_ID: 53xxxx 834 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
int main(int argc, char* argv[])
{
        int a,b,t;
        while(scanf("%d %d",&a,&b)==2){
                printf("[%d",a/b);
                t=a;
                a=b;
                b=t%a;
                if(b!=0)printf(";%d",a/b);
                while(b!=0){
                        t=a;
                        a=b;
                        b=t%a;
                        if(b==0) break;
                        printf(",%d",a/b);
                }
                printf("]\n");
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
