/* @JUDGE_ID: 6722RJ 492 C++ */
#include <stdio.h>
#include <ctype.h>
int main()
{
     char a,h;
     int head=1,s1=0,s2=0;
     while(1==scanf("%c",&a))
     {
           if(isalpha(a)!=0)
           {
              if(head)
              {
                 head=0;
                 if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
                 {
                    s1=1;
                    printf("%c",a);
                 }
                 else
                 {
                    h=a;
                    s2=1;
                 }
              }
              else
              {
                 printf("%c",a);
              }
           }
           else
           {
              head=1;
              if(s1)
              {
                 printf("ay%c",a);
                 s1=0;
              }
              else if(s2)
              {
                 printf("%cay%c",h,a);
                 s2=0;
              }
              else
                  printf("%c",a);
           }
     }
        return 0;
}
