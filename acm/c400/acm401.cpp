/* @JUDGE_ID: 53xxxx 401 C++ */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char tab[]={"A///3//HIL/JM/O///2TUVWXY5"};
char tab2[]={"/1SE/Z//8/"};
char in[500];
int is_pld(char *str)
{
    int i;
    int len=strlen(str);
    for(i=0;i*2<len;i++)
    {
        if(str[i]!=str[len-i-1])
        {
          return 0;
        }
    }
    return 1;
}
int is_mi(char *str)
{
    int i;
    int len=strlen(str);
    for(i=0;i*2<len;i++)
    {
       if(isalpha(str[i]))
       {
         if(tab[(str[i]-'A')]!=str[len-i-1])
         {
           return 0;
         }
       }
       else
       {
         if(tab2[(str[i]-'0')]!=str[len-i-1])
         {
           return 0;
         }
       }
    }
    return 1;

}
int main(int argc, char* argv[])
{
   int pld,mi;
   while(scanf("%s",in)!=EOF)
   {
      printf("%s -- ",in);
      pld=is_pld(in);
      mi=is_mi(in);
      if(pld && mi )
      {
         printf("is a mirrored palindrome.\n");
      }
      else  if(!pld && mi)
      {
         printf("is a mirrored string.\n");
      }
      else if( pld && !mi)
      {
         printf("is a regular palindrome.\n");
      }
      else
      {
         printf("is not a palindrome.\n");
      }
   }
        return 0;
}
