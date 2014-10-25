/* @JUDGE_ID: 53xxxx 305 C++ */
#include <stdio.h>
int k;
int j[13]={0};
int test(int c)
{
    int pos,wk=k;
    int i,arr[30],len=k*2;
     pos=(c-1)%len;
    for(i=0;i<k*2;i++)
    {
        arr[i]=i+1;
    }
    while(wk>0)
    {
      if(pos<k) return 0;
      for(i=pos+1;i<len;i++)
      {
          arr[i-1]=arr[i];
      }
      wk--;
      len--;
      pos=(pos+c-1)%len;

    }
    return 1;
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
      if(k==1)
      {
       printf("2\n");
      }
      else if(j[k-1]>0)
      {
       printf("%d\n",j[k-1]);
      }
      else
      {
       for(i=k;;i++)
       {
           if(test(i)) break;
       }
       printf("%d\n",i);
       j[k-1]=i;
      }
    }
        return 0;
}

