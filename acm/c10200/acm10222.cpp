/* @JUDGE_ID: 53xxxx 10222 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <ctype.h>
#include <stdio.h>
char  tab[]={"qwertyuiop[]asdfghjkl;'zxcvbnm,./"};
char tab1[]={"[]qwertyuiop;'asdfghjkl./zxcvbnm,"};
int main(int argc, char* argv[])
{
        char a;
        int i;
        while((a=getchar())!=EOF)
        {
                if(isupper(a))
                        a=a-'A'+'a';
                for(i=0;i<33;i++)
                {

                        if(tab[i]==a){
                                printf("%c",tab1[i]);
                                break;}
                }
                if(i==33)printf("%c",a);
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
