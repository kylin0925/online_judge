#include <stdio.h>
int land[110][110]={0};
int check_v(int land[][110],int n,int m){
    int i,j;
    int found = 0;
    for(i=1;i<m-1;i++){
        for(j=1;j<n;j++){
            if(land[j][i]!=land[j-1][i])  
                break;
        }
        printf("v %d \n",j);
        if(j == n)
            found = 1;
    }
    return found;
}
int check_h(int land[][110],int n,int m){
    int i,j;
    int found = 0;
//printf("%s\n",__func__);
    for(i=1;i<n-1;i++){
        for(j=1;j<m;j++){
            if(land[i][j]!=land[i][j-1])  
                break;
        }
        printf("h %d \n",j);
        if(j == m)
            found = 1;

    }
    return found;
}

int check(int land[][110],int n,int m){
    if( check_v(land,n,m) && check_h(land,n,m) )return 1;
    else
        return 0;
}
int main(int argc,char **argv){
    int t,n,m;
    int idx=1;
    int i,j;
    scanf("%d",&t);
    for(idx=1;idx<=t;idx++){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++){
                scanf("%d",&land[i][j]);
            }
        }
        if(n==1 || m ==1){
            printf("Case #%d: YES\n",idx); 
        }
        else if(check(land,n,m)){
            printf("Case #%d: YES\n",idx); 
        }else{
            printf("Case #%d: NO\n",idx); 
        }
    }
    return 0;
}
