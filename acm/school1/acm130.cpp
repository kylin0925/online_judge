/* @JUDGE_ID: 53xxxx 130 C++ */
#include <stdio.h>
int k;

int test(int len,int c)
{
    int pos=0,wk=len-1;
    int i,arr[300];
    for(i=0;i<len;i++)
    {
        arr[i]=i+1;
    }
    while(wk>1)
    {
      for(i=pos+1;i<len;i++)
      {
          arr[i-1]=arr[i];
      }
      wk--;
      len--;
      pos=(pos+c-1)%len;

    }
    return arr[0];
}
int main(int argc, char* argv[])
{
    int n,i,sav;

    while(1)
    {
      scanf("%d %d",&n,&k);
      if(!n && !k) break;
      sav=test(n,k);
      printf("%d\n",sav);
    }
        return 0;
}
