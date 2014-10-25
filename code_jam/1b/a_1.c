#include <stdio.h>
#include <string.h>
char buff[1050000]={0};
int chk[1050000]={0};
int is_vow(char a){

   if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
        return 1;
    else
        return 0;
 
}
void make_chk(int n){
    int i,cnt=0;
    //printf("buff %s\n",buff);
    for(i=0;i<n;i++){
        if(is_vow(buff[i])==0)
            cnt++;
        chk[i]=cnt;
    }
/*    chk[n]=chk[n-1];
    for(i=0;i<=n;i++){
        printf("%d ",chk[i]);
    }

        printf("\n");
  */  
}
int main(int argc,char ** argv){
    int t,n,l,cnt,sub;
    int i,j,k,str_len;
    scanf("%d",&n);
    for(t=0;t<n;t++){
        scanf("%s %d",buff,&l);
        str_len = strlen(buff);
        make_chk(str_len);    
        cnt = 0;
        sub = 0;
        for(i=0;i<str_len-l;i++){
            for(j=i+l;j<str_len;j++){
                //printf("chk[%d] - sub(%d) = %d\n",j,sub,chk[j]-sub);
                if(chk[j]-sub>=l)
                    break;
            }
            cnt+=str_len-j;
            printf("start %d found pos %d cnt %d\n",i,j,cnt);
            if(is_vow(buff[i])==0) sub++;
            
            //printf("sub %d \n",sub);
        } 
        sub =0;
        if(chk[i+l]>=l) cnt++;
        printf("Case #%d: %d\n",t+1,cnt);
    }
    return 0;
}
