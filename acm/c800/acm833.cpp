/* @JUDGE_ID: 53xxxx 833 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
int bx1[10000];
int by1[10000];
int bx2[10000];
int by2[10000];
int n,n1,n2,i;
int max(int a,int b){return ((a>b)?a:b);};
int min(int a,int b){return ((a>b)?b:a);};
float dis(int x,int y,int n){
        float m=(float)(by2[n]-by1[n])/(float)(bx2[n]-bx1[n]);
        float c=by2[n]-m*bx2[n];
        float cy=m*x+c;
        return (float)sqrt((y-cy)*(y-cy));
}
void check(int x,int y){
        int m[10000]={0};
        int i;
        int tx=x,ty=y,nb=-1;
        float d,mind=99999999;
        while(ty!=0){
                mind=99999999;
                nb=-1;
                for(i=0;i<n1;i++){
                        if(m[i]==0){
                                if(tx<max(bx1[i],bx2[i])&&tx>min(bx1[i],bx2[i])){
                                        if(ty>min(by1[i],by2[i]))
                                        {
                                                d=dis(tx,ty,i);
                                                if(d<mind){nb=i;mind=d;}
                                        }
                                }
                        }
                }
                if(nb!=-1)tx=((by1[nb]>by2[nb])?bx2[nb]:bx1[nb]);
                (nb==-1)?ty=0:(ty=min(by1[nb],by2[nb]));
                m[nb]=1;
        }
        printf("%d\n",tx);
}
int main(int argc, char* argv[])
{
        int x,y;
        scanf("%d",&n);
        for(;n>0;n--){
                scanf("%d",&n1);
                for(i=0;i<n1;i++){
                        scanf("%d %d %d %d",&bx1[i],&by1[i],&bx2[i],&by2[i]);
                        //printf("%d",bordx1[i]);
                }
                scanf("%d",&n2);
                for(i=0;i<n2;i++){
                        scanf("%d %d",&x,&y);
                        check(x,y);
                }
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
