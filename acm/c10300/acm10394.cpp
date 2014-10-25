/* @JUDGE_ID: 53xxxx 10394 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
int p[100002][2]={0};
bool pp[20000005]={false};

int main(int argc, char* argv[])
{
        int i,j,n,k;
        for(i=3;i<=20000000;i+=2){
                if(pp[i]==false){
                        for(j=2;i*j<=20000000; j++){
                                pp[i*j]=true;
                        }
                }
        }
        for(i=3,j=1;j<=100000 && i<=20000000;i+=2){
                if(!pp[i] && !pp[i+2]){
                        p[j][0]=i;p[j++][1]=i+2;
                }
        }
        while(scanf("%d",&n)==1){
                printf("(%d, %d)\n",p[n][0],p[n][1]);
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */

