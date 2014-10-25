/* @JUDGE_ID: 53xxxx 155 C++ */
#include <stdio.h>
int con=0;
int test(int s,int x,int y,int cx,int cy)
{
    if(x<cx-s) return 0;
    if(x>cx+s) return 0;
    if(y<cy-s) return 0;
    if(y>cy+s) return 0;
    return 1;
}
void cal(int s,int x,int y,int cx,int cy)
{
     if(test(s,x,y,cx,cy))
       con++;
     if(s==1) return;

     if(test(s  ,x,y,cx-s,cy-s))
         cal(s/2,x,y,cx-s,cy-s);

     if(test(s  ,x,y,cx+s,cy-s))
         cal(s/2,x,y,cx+s,cy-s);

     if(test(s  ,x,y,cx-s,cy+s))
         cal(s/2,x,y,cx-s,cy+s);

     if(test(s  ,x,y,cx+s,cy+s))
         cal(s/2,x,y,cx+s,cy+s);

}
int main()
{
  int k,x,y,tr=1;

  while(tr)
  {
     con=0;
     scanf("%d %d %d",&k,&x,&y);
     if(!k && !x && !y) break;
     cal(k,x,y,1024,1024);
     printf("%3d\n",con);
  }
  return 0;
}
