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
    for(i=0;i<n;i++){
        printf("%d ",chk[i]);
    }
    printf("\n");
  
}

int main(int argc,char ** argv){
    int t,n,l,cnt,c;
    int i,x,y,z,str_len;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %d",buff,&l);
        //printf("%s\n",buff);
       
        cnt=0;
        str_len = strlen(buff);
        //printf("str len %d\n",str_len);
        make_chk(str_len);
        c=0;    
        for(x=0;x<str_len-l+1;x++){
            if(is_vow(buff[x]) == 1) c=0;
            for(z=x+l-1; z<str_len ;z++)
            {
                    if(chk[z]-c>=l)break;  
            }
            
            cnt+=str_len-z;

            printf("end x %d  z %d c %d cnt %d\n",x,z,c,cnt);
            
            if(is_vow(buff[x]) == 0) c++;
            else
                c=0;
        }
    
        printf("Case #%d: %d\n",i+1,cnt);
    }
    return 0;
}
