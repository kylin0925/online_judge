#include <stdio.h>
void sov(int a,int b,int c,long con)
{
 char   aa='c',bb,cc;
 for(;con>0;con--)
 {
   if(aa=='c'){ a--;c++;aa='b';bb=' ';cc=' ';continue;}
   else if(aa=='b'){ a--;b++;cc='b';aa=' ';bb=' ';continue;}
   else if(cc=='b'){ c--;b++;bb='a';aa=' ';cc=' ';continue;}
   else if(bb=='a'){ b--;a++;bb='c';aa=' ';cc=' ';continue;}
   else if(bb=='c'){ b--;c++;aa='c';bb=' ';cc=' ';continue;}
 }
 printf("%d %d %d\n",a,b,c);
}
int main()
{
    int a,b=0,c=0;
    long con;
    while(scanf("%d %d",&a,&con)==2)
    {
       if(a==0&&con==0) break;
       sov(a,b,c,con);
    }
        return 0;
}
 
