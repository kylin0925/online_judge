#include <stdio.h>
#include <string.h>
#include <math.h>
int max;
char s1[100]="abcdefghi";
char s2[100]="cbaedghfi";

char tab[100];
int cnt,d;
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
void tree_t(int i){
        if(i<=d){
                tree_t(left(i));
                tree_t(right(i));
                if(tab[i]!='\0')
                        printf("%c",tab[i]);
        }
}
void build_tree(int n,char in_order[]){
        char left[50]={'\0'};
        char right[50]={'\0'};
        char *tmp;
        int l;
        if(cnt<max){
                tmp=strrchr(in_order,s1[cnt]);
                tab[n]=s1[cnt++];
                printf("%s\n",tab);
                l=tmp-in_order;
                strncpy(left,in_order,l);
                for(int i=l+1,j=0;i<strlen(in_order);i++)right[j++]=in_order[i];
                if(strlen(left)>0){
                        build_tree(n*2+1,left);
                }
                if(strlen(right)>0){
                        build_tree(n*2+2,right);
                }
        }

}
int main(int argc, char* argv[])
{
        cnt=0;
        max=strlen(s1);
        d=(int)(ceil((log(max)/log(2)))+1);
        d=pow(2,(double)d);
        build_tree(0,s2);
        tree_t(0);
        return 0;
}
