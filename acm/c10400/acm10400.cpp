/* @JUDGE_ID: 53xxxx 10400 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int arr[101]={0};
char res[101];
int resop,p,stop,ctr;
int num[64001][101];
int a,b,c,d;
void set_arr(){
        int i,j;
        for(i=0;i<64001;i++){
                for(j=0;j<=100;j++)
                        num[i][j]=0;
        }
}
void print_res(){
        int f=0,i;
        for(i=0;i<p-1;){
                if(f==0){printf("%d",arr[i]);f=1;}
                else{printf("%c",res[i++]);f=0;}
        }
        printf("%d=%d\n",arr[p-1],resop);
}
void rec(int n,int s,char op){
        int ctr1=0;
        res[s-2]=op;
        if(n==resop && s==p){
                print_res();
                stop=1;
        }else if(stop==0 && s<p){
                if(abs(n+arr[s])<=32000){
                        if(num[n+arr[s]+32000][s]==0 || (n+arr[s])==resop){
                         num[n+arr[s]+32000][s]=1;
                         rec(n+arr[s],s+1,'+');
                         if(stop==1) return;
                        }
                }
                if(abs(n-arr[s])<=32000){
                        if(num[n-arr[s]+32000][s]==0|| (n-arr[s])==resop){
                         num[n-arr[s]+32000][s]=1;
                         rec(n-arr[s],s+1,'-');
                         if(stop==1) return;
                        }
                }
                if(abs(n*arr[s])<=32000){
                        if(num[n*arr[s]+32000][s]==0 || (n*arr[s])==resop){
                           num[n*arr[s]+32000][s]=1;
                           rec(n*arr[s],s+1,'*');
                           if(stop==1) return;
                        }
                }
                if((n%arr[s])==0){
                        if(abs(n/arr[s])<=32000){
                           if(num[n/arr[s]+32000][s]==0 ||(n/arr[s])==resop){
                                num[n/arr[s]+32000][s]=1;
                                rec(n/arr[s],s+1,'/');
                                if(stop==1) return;
                           }
                        }
                }
        }
}
int main(int argc, char* argv[])
{
        int n,i;
        scanf("%d",&n);
        for(;n>0;n--){
                scanf("%d",&p);
                for(i=0;i<p;i++)scanf("%d",&arr[i]);
                scanf("%d",&resop);
                stop=0;
                ctr=0;
                if(stop==0 && abs(arr[0]+arr[1])<=32000){
                        set_arr();
                        num[arr[0]+arr[1]+32000][1]=1;
                        rec(arr[0]+arr[1],2,'+');
                }
                if(stop==0 && abs(arr[0]-arr[1])<=32000){
                        if(num[arr[0]-arr[1]][1]==0 ||(arr[0]-arr[1])==resop){
                           num[arr[0]-arr[1]+32000][1]=1;
                           rec(arr[0]-arr[1],2,'-');
                        }
                }
                if(stop==0 && abs(arr[0]*arr[1])<=32000){
                        if(num[arr[0]*arr[1]][1]==0|| arr[0]*arr[1]==resop){
                           num[arr[0]*arr[1]+32000][1]=1;
                           rec(arr[0]*arr[1],2,'*');
                        }
                }
                if(arr[0]%arr[1]==0){
                  if(stop==0 && abs(arr[0]/arr[1])<=32000){
                     if(num[arr[1]/arr[1]][1]==0|| arr[0]/arr[1]==resop){
                        num[arr[0]/arr[1]+32000][1]=1;
                        rec(arr[0]/arr[1],2,'/');
                     }
                }}
                if(stop==0)printf("NO EXPRESSION\n");
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
