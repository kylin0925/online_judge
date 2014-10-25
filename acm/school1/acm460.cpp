/* @JUDGE_ID: 53xxxx 460 C++ */
#include <stdio.h>
int max(int n,int m){  return(n>m)?n:m;}
int min(int n,int m){  return(n<m)?n:m;}
int main(int argc, char* argv[])
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    int n,lx,ly;
    scanf("%d",&n);
    for(;n>0;n--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
        lx=min(x2,x4)-max(x1,x3);
        ly=min(y2,y4)-max(y1,y3);
        if(lx>0 && ly>0)
        {
           printf("%d %d",max(x1,x3),max(y1,y3));
           printf(" %d %d\n",min(x2,x4),min(y2,y4));
        }
        else
        {
           printf("No Overlap\n");
        }
    }

        return 0;
}
 
