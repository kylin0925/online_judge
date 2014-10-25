/* @JUDGE_ID: 53xxxx 10018 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>
int n;
unsigned long a;
void mystrrev(char *s)
{
        int i,len=strlen(s);
        char t;
        for(i=0;i<(len/2);i++)
        {
                t=s[i];
                s[i]=s[len-i-1];
                s[len-i-1]=t;
        }
}
int check(unsigned long n)
{
        char tmp[30];
        int len,i;
        sprintf(tmp,"%u",n);
        len=strlen(tmp);
        if(len==1) return 0;
        for(i=0;i<(len/2);i++)
        {
                if(tmp[i]!=tmp[len-i-1]) return 0;
        }
        return 1;
}
void sov(unsigned long n)
{
        char strn1[30],strn2[30];
        unsigned long a,b;
        int time=1;
        a=n;

        while(1)
        {
                sprintf(strn1,"%u",a);
                strcpy(strn2,strn1);
                mystrrev(strn2);
                sscanf(strn2,"%u",&b);
                a=a+b;
                if(check(a))
                {
                    sprintf(strn1,"%d",a);
                    printf("%d %u\n",time,a);
                    break;
                }
                time++;
        }
}
int main(int argc, char* argv[])
{
        scanf("%d",&n);
        for(;n;n--)
        {
                scanf("%d",&a);
                if(a==0)printf("0\n");
                else
                        sov(a);
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
  
