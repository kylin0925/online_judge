/* @JUDGE_ID: 53xxxx 110 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

int len;
char tab[]={"abcdefgh"};
char sp=' ';
void rec(char ans[],int p,int l,int tn)
{
        char tmp[10];
        memset(tmp,'\0',10);
        strcpy(tmp,ans);
        if(l==len){
                printf("%*cwriteln(%c",l*2,sp,tmp[0]);
                for(int i=1;i<len;i++)
                        printf(",%c",tmp[i]);
                printf(")\n");
        }
        else{
                tmp[p]=tab[tn];

                for(int i=l;i>=0;i--)
                {
                        if(i==l){
                                printf("%*cif %c < %c then\n",l*2,sp,tmp[i-1],tmp[i]);
                        }
                        else if(i<l && i>0){
                                printf("%*celse if %c < %c then\n",l*2,sp,tmp[i-1],tmp[i]);
                        }else if(i==0){
                                printf("%*celse\n",l*2,sp);
                        }
                        rec(tmp,p+1,l+1,tn+1);

                        char t;
                        if(i>0){ t=tmp[i-1];tmp[i-1]=tmp[i];tmp[i]=t;}
                }
                strcpy(tmp,ans);
        }
}
int main(int argc, char* argv[])
{
        int n;
        char tmp[10];
        scanf("%d",&n);
        for(;n;n--)
        {
                scanf("%d",&len);
                for(int i=0;i<10;tmp[i]='\0',i++);
                tmp[0]=tab[0];
                printf("program sort(input,output);\n");
                printf("var \n");
                printf("a");
                for(int i=1;i<len;i++)printf(",%c",tab[i]);
                printf(" : integer;\n");
                printf("begin\n");
                printf("  readln(a");
                for(int i=1;i<len;i++)printf(",%c",tab[i]);
                printf(");\n");
                rec(tmp,1,1,1);
                printf("end.\n");
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
