/* @JUDGE_ID: 53xxxx 344 C */
/*@begin_of_source_code*/
#include <stdio.h>
#include <string.h>
int table[110][10];
char tenno[11][11]={"\0","x","xx","xxx","xl","l","lx",
                    "lxx","lxxx","xc","c"};
char ono[10][10]={"\0","i","ii","iii","iv","v","vi",
                  "vii","viii","ix"};
char c[10]={'i','v','x','l','c'};
void rno(int n)
{
        char tmp[10],tno[10],o[10],hun;
        int i,con[5]={0};
        sprintf(tmp,"%03d",n);
        strcpy(tno,tenno[tmp[1]-'0']);
        strcpy(o,ono[tmp[2]-'0']);
        con[4]=tmp[0]-'0';
        for(i=0;i<strlen(tno);i++)
        {
                if(tno[i]=='x')
                 con[2]++;
                else if(tno[i]=='l')
                 con[3]++;
                else if(tno[i]=='c')
                 con[4]++;
        }
        for(i=0;i<strlen(o);i++)
        {
                if(o[i]=='i')
                 con[0]++;
                else if(o[i]=='v')
                 con[1]++;
                else if(o[i]=='x')
                 con[2]++;
        }
        for(i=0;i<5;i++)
        {
                table[n][i]=con[i]+table[n-1][i];
        }
}
int main(int argc, char* argv[])
{
        int i,j,n;
        for(i=1;i<=100;i++)
        {
           rno(i);
        }
        while(scanf("%d",&n)==1)
        {
                if(!n) break;
                printf("%d: ",n);
                printf("%d i",table[n][0]);
                for(i=1;i<5;i++)
                {
                   printf(", %d %c",table[n][i],c[i]);
                }
                printf("\n");
        }

        return 0;
}
/*@end_of_source_code*/

 
