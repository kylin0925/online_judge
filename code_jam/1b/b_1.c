#include <stdio.h>
#include <string.h>

int main(int argc,char ** argv){
    int tt,t,x,y,tmp;
    int i,j;
    scanf("%d",&tt);
    for(i=0;i<tt;i++){
        scanf("%d %d",&x,&y);
        printf("Case #%d: ",i+1);
        if(x>0)printf("E");
        else if(x<0)printf("W");
        t = x <0 ? -x:x;
        for(j=0;j<t-1;j++)printf("%s",x>0?"WE":"EW");
        t = y <0 ? -y:y;
        for(j=0;j<t;j++)printf("%s",y>0?"SN":"NS");
        printf("\n");
    }   
    printf("");
    return 0;
}
