/* @JUDGE_ID: 53xxxx 10106 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>
void mul(char a[],char b[],char c[])
{
        int i,j,lena,lenb,temp,ca;
        char tmp[5000];
        lena=strlen(a);lenb=strlen(b);
        if(lena<lenb)
        {
                temp=lena;  strcpy(tmp,a);
                lena=lenb;  strcpy(a,b);
                lenb=temp;  strcpy(b,tmp);
        }

        for(i=0;i<lenb;i++)
        {
                ca=0;
                for(j=0;j<lena;j++)
                {
                        temp=(a[j]-'0')*(b[i]-'0')+ca+(c[i+j]-'0');
                        c[i+j]=temp%10+'0';
                        ca=temp/10;
                }
                if(ca>0)
                {
                        c[i+lena]=ca+'0';
                }
        }
        if(ca==0)
        {
                c[lena+lenb-1]='\0';
        }
        else
        {
                c[lena+lenb-1]=ca+'0';
                c[lena+lenb]='\0';
        }
}
void rv(char a[])
{
        int len,i;
        char t;
        len=strlen(a);
        for(i=0;i<len/2;i++)
        {
                t=a[len-1-i];
                a[len-1-i]=a[i];
                a[i]=t;
        }
}
int main(int argc, char* argv[])
{
        char a[300],b[300],c[600];
        while(gets(a))
        {
                gets(b);
                memset(c,'0',600);
                rv(a);rv(b);
                mul(a,b,c);
                rv(c);
                if(c[0]=='0') printf("0\n");
                else printf("%s\n",c);
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
