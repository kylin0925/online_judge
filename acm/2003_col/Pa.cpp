#include <stdio.h>
int find_ans(int n){
        int tab[]={2354,1463,1265,1562,1364,2453};
        int j;
        for(j=0;j<6;j++){
                if(n==tab[j]){
                        return j+1;
                }
        }
}
int sov(char s1[]){
        int u,l,d,r,tmp,tmp1,tmp2,min;
        d=s1[0]-'0';
        r=s1[2]-'0';
        u=7-d;
        l=7-r;
        tmp1=((u<d)?u:d);
        tmp2=((r>l)?l:r);
        min=((tmp1<tmp2)?tmp1:tmp2);
        //u r d l
        tmp=min*1000+(7-min)*10;
        if(min==tmp2){
                if(d>r){
                        tmp+=u*100+d;
                }else{
                        tmp+=d*100+u;
                }
        }else{
                if(d>r){
                        tmp+=l*100+r;
                }else{
                        tmp+=r*100+l;
                }
        }
        return find_ans(tmp);
 }
int main(int argc, char* argv[])
{
        int i,n1,n2;
        char s[10],s1[10],s2[10],r[10];
        gets(r);
        //n=atoi(n);
        i=1;
        while(1){
                gets(s1);
                gets(s2);
                gets(s2);
                gets(s);

                n1=sov(s1);
                n2=7-sov(s2);
                printf("Case %d: The top face is %d and the bottom face is %d\n",i++,n1,n2);
                if(s[0]=='.') break;
        }
        return 0;
}
