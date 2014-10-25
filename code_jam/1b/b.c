#include <stdio.h>
#include <string.h>
char buff[500]={0};
int chk[1000][1000]={0};
int end_x,end_y,start_x,start_y,stop_x,stop_y;
int found;
int max_step = 500;
int offset=100;
void dfs(int step,int x,int y){
    int s=step+1;
    // printf("step %d %d %d\n",step,x,y);
    if(x==end_x && y == end_y ){
        found = 1;
        buff[step]='\0';
    //    printf("found \n");
        return;
    }
    chk[x+offset][y+offset]=1;
    //printf("step %d chk E\n",step);
    if(!found && x+s <= stop_x && chk[x+s+offset][y+offset]!=1 ){
        buff[step]='E';
        //printf("step %d move E\n",step);
        dfs(s,x+s,y);
    }

    //printf("step %d chk S\n",step);
    if(!found &&y-s >= start_y && chk[x+offset][y-s+offset]!=1 ){
        buff[step]='S';
        //printf("step %d move S\n",step);
        dfs(s,x,y-s);
    }

    //printf("step %d chk W\n",step);
    if(!found &&x-s >= start_x && chk[x-s+offset][y+offset]!=1  ){
        buff[step]='W';
        //printf("step %d move W\n",step);
        dfs(s,x-s,y);
    }
    
    //printf("step %d chk N %d\n",step,chk[x+offset][y+s+offset]);
    if(!found &&y+s<=stop_y && chk[x+offset][y+s+offset]!=1 ){
        buff[step]='N';
        //printf("step %d move N\n",step);
        dfs(s,x,y+s);
    }
    chk[x+offset][y+offset]=0;
}
int main(int argc,char ** argv){
    int t,x,y;
    int i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d",&x,&y);
        end_x=x;
        end_y=y;
        found =0;

        start_x = x > 0 ? -x:x;
        start_y = y > 0 ? -y:y;
        stop_x = x>0?x:-x;
        stop_y = y > 0 ? y : -y;
        //printf("start %d %d end %d %d\n",start_x,start_y,stop_x,stop_y);

        dfs(0,0,0);
        for(x=0;x<1000;x++)
            for(y=0;y<1000;y++)chk[x][y]=0;
        printf("Case #%d: %s\n",i+1,buff);
        for(x=0;x<500;x++) buff[x]=0;
    }
    return 0;
}
