/* @JUDGE_ID: 53xxxx 713 C++ */
#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],b[100],r[101];
    int  len1,len2,i,c,n,k;
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
         scanf("%s %s",&a,&b);
         c=0;
         if(strlen(a)>strlen(b))
         {
            len1=strlen(b);
            len2=strlen(a);
         }else{
            len1=strlen(a);
            len2=strlen(b);
         }
         for(i=0;i<len1;i++)
         {
             r[i]=((a[i]-'0')+(b[i]-'0')+c)%10+'0';
                c=((a[i]-'0')+(b[i]-'0')+c)/10;
         }
         for(i=len1;i<len2;i++)
         {
             r[i]=((a[i]-'0')+c)%10+'0';
                c=((a[i]-'0')+c)/10;
         }
         if(c==0)
         {
          r[len2]='\0';
         }
         else
         {
          r[len2]=c+'0';
          r[len2+1]='\0';
          len2++;
         }
         for(i=0;i<len2;i++)
         {
          if(r[i]!='0')
              printf("%c",r[i]);
         }
         printf("\n");
         for(i=0;i<100;i++)
         {
             a[i]='\0';
             b[i]='\0';
         }
    }

        return 0;
}
 
