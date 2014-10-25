/* @JUDGE_ID: 53xxxx 10104 C++ */
#include <stdio.h>
#include <stdlib.h>
int euclid(int a, int b, int *x, int *y)
{
  int gcd, x1, y1;

  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }
  else {
    gcd = euclid(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b)*y1;
    return gcd;
  }
}
int main(int argc, char* argv[])
{
    int a,b;
    int i,j;
    int gcdn,tg,lcm;
    int x;
    int y;
    while(scanf("%d %d",&a,&b)==2)
    {
       gcdn=euclid(a,b,&x,&y);
       printf("%d %d %d\n",x,y,gcdn);
    }
        return 0;
}
