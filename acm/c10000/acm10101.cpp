/*@JUDGE_ID:53xxxx 10101   C "«¢«¢" */
/*@BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
        char buff[20],p[20];
        char *nums[]={"kuti","lakh","hajar","shata"};
        int n=1,len,f;
        while(scanf("%s",buff)==1)
        {
                f=0;
                len=strlen(buff);

                if(strcmp(buff,"0")==0 ||strcmp(buff,"00")==0 || strcmp(buff,"000")==0)
                {
                        printf("%4d. 0\n",n++);
                        continue;
                }
                memset(p,'0',15-len);
                p[15-len]='\0';
                strcat(p,buff);
                printf("%4d.",n++);
                if(p[0]>'0'){printf(" %c %s",p[0],nums[0]);f=1;}
                if(p[1]>'0' || p[2]>'0')
                {printf(" %d %s",(p[1]-'0')*10+(p[2]-'0'),nums[1]);f=1;}
                if(p[3]>'0' || p[4]>'0')
                {printf(" %d %s",(p[3]-'0')*10+(p[4]-'0'),nums[2]);f=1;}
                if(p[5]>'0')
                {printf(" %c %s",p[5],nums[3]);f=1;}
                if(p[6]>'0' || p[7]>'0')printf(" %d %s",(p[6]-'0')*10+(p[7]-'0'),nums[0]);
                else if(f) printf(" %s",nums[0]);
                if(p[8]>'0' || p[9]>'0')printf(" %d %s",(p[8]-'0')*10+(p[9]-'0'),nums[1]);
                if(p[10]>'0' || p[11]>'0')printf(" %d %s",(p[10]-'0')*10+(p[11]-'0'),nums[2]);
                if(p[12]>'0')printf(" %c %s",p[12],nums[3]);
                if(p[13]>'0' || p[14]>'0')printf(" %d",(p[13]-'0')*10+(p[14]-'0'));
                printf("\n");
        }
        return 0;
}
/*@END_OF_SOURCE_CODE*/
