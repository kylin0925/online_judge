/* @JUDGE_ID: 53xxxx 10409 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
int die[6];
void change(int a1,int a2,int a3,int a4){
        int tmp;
        tmp=die[a1];
        die[a1]=die[a2];
        die[a2]=die[a3];
        die[a3]=die[a4];
        die[a4]=tmp;
}
int main(int argc, char* argv[])
{
        int n,top,i;
        char str[100];
        while(1){
                scanf("%d",&n);
                if(n==0) break;
                for(i=0;i<6;die[i++]=i+1);
                for(;n>0;n--){
                        scanf("%s",str);
                        if(str[0]=='n'){
                                change(0,4,5,1);
                        }
                        else if(str[0]=='e'){
                                change(0,2,5,3);
                        }
                        else if(str[0]=='s'){
                                change(0,1,5,4);
                        }
                        else if(str[0]=='w'){
                                change(0,3,5,2);
                        }
                }
                printf("%d\n",die[0]);
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
