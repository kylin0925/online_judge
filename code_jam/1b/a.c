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
            
        for(z=l;z<=str_len;z++){
            c=0;
            for(x=0;x<str_len - z +1;x++){
                c=0;
                for(y=x;y<x+z ;y++)
                {
                    if(buff[y]=='a'||
                            buff[y]=='e'||buff[y]=='i'||buff[y]=='o'||buff[y]=='u')
                    {
                        if(c<l)
                            c=0;
                    }else c++;
                        
                }
            
               // printf("end z %d x %d y %d c %d\n",z,x,y,c);
                if(c>=l)cnt++;
            }
        }
    
        printf("Case #%d: %d\n",i+1,cnt);
    }
    return 0;
}
