#include <stdio.h>
#include <string.h>
int main(int argc,char ** argv){
    int t,n,l,cnt,c;
    int i,x,y,z,str_len;
    char buff[1050000]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %d",buff,&l);
        //printf("%s\n",buff);
        cnt=0;
        str_len = strlen(buff);
        //printf("str len %d\n",str_len);
            
        for(x=0;x<str_len-l+1;x++){
            c=0;
            for(y=l;y<=str_len  && c<l;y++){
                c=0;
                for(z=x;z<x+y+1 && z<str_len ;z++)
                {
                    if(buff[z]=='a'|| buff[z]=='e'||
                        buff[z]=='i'||buff[z]=='o'||buff[z]=='u')
                    {
                        if(c<l)
                            c=0;
                    }else c++;
                      
                    if(c>=l)break;  
                }
            
                printf("end x %d y %d z %d c %d\n",x,y,z,c);
                if(c>=l)cnt+=str_len-z;
            }
            printf("x %d\n",x);
        }
    
        printf("Case #%d: %d\n",i+1,cnt);
    }
    return 0;
}
