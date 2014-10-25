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
        else
            cnt=0;
        chk[i]=cnt;
    }
/*    for(i=0;i<n;i++){
        printf("%d ",chk[i]);
    }
    printf("\n");
  */
}
int main(int argc,char ** argv){
    int t,n,l,cnt,last,r;
    int i,j,k,str_len;
    scanf("%d",&n);
    for(t=0;t<n;t++){
        scanf("%s %d",buff,&l);
        str_len = strlen(buff);
        make_chk(str_len);    
        cnt = 0;
        last = -1;
        r=0;
        for(i=0;i<str_len;i++){
            if(is_vow(buff[i])){
                if((i+l)<str_len && chk[i+l]>=l){
                    r++;
                }
                cnt=0;
            }else{
                cnt++;
                if(cnt >=l){
                    if(last!=-1){
                        r+=(str_len -i )*(i-last);
                    }else{
                        r+=str_len-l;
                    }
                    last =i;
                }
            }
    //        printf("r %d\n",r);
        } 
        printf("Case #%d: %d\n",t+1,r);
    }
    return 0;
}
