/* @JUDGE_ID: 53xxxx 151 C++ */
#include <stdio.h>
int k;

int test(int c)
{
    int pos,wk=k;
    int i,arr[300],len=k;
     pos=0;
    for(i=0;i<k;i++)
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
    int i;

    while(1)
    {
      scanf("%d",&k);
      if(k==0)
      {
        return 0;
        break;
      }
       for(i=1;;i++)
       {
        if(test(i)==13) break;
       }
         printf("%d\n",i);
           
    }
        return 0;
}

