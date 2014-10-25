/* @JUDGE_ID:  53xxxx  101  C++  */
#include <stdio.h>
int arr[30][30];
int top[30];
struct point{
 int x;
 int y;
 int val;
};
void init(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
       arr[i][0]=i;
       top[i]=1;
       for(j=1;j<n;j++)
       {
          arr[i][j]=-1;
       }
    }
}
void pr(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
      printf("%2d: ",i);
      for(j=0;arr[i][j]!=-1;j++)
      {
         if(j>0)printf(" ");
         printf("%d",arr[i][j]);
      }
      printf("\n");
    }
}
point findp(int n,int num)
{
   point t;
   int i,j;
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           if(arr[i][j]==num)
           {
             t.x=j;
             t.y=i;
             t.val=num;
             return t;
           }
       }
   }
}
void putback(point b)
{
     int i,t;
     for(i=b.x+1;arr[b.y][i]!=-1;i++)
     {
       t=arr[b.y][i];
       arr[t][0]=t;
       arr[b.y][i]=-1;
       top[b.y]--;
       top[t]++;
     }
}
void domovon(point a,point b)
{
   if(top[a.y]==1 && top[b.y]==1)
   {
      arr[b.y][b.x+1]=a.val;
      arr[a.y][0]=-1;
      top[b.y]++;
      top[a.y]--;
   }
   else if(top[a.y]==1)
   {
       putback(b);
       arr[b.y][b.x+1]=a.val;
       arr[a.y][0]=-1;
       top[b.y]++;
       top[a.y]--;
   }
   else if(top[b.y]==1)
   {
       putback(a);
       arr[b.y][b.x+1]=a.val;
       arr[a.y][a.x]=-1;
       top[b.y]++;
       top[a.y]--;
   }
   else
   {
       putback(a);
       putback(b);
       arr[b.y][b.x+1]=a.val;
       arr[a.y][a.x]=-1;
       top[b.y]++;
       top[a.y]--;
   }
}
void domovov(point a,point b)
{
    if(top[a.y]==0)
   {
      arr[b.y][top[b.y]]=a.val;
      arr[a.y][0]=-1;
      top[b.y]++;
      top[a.y]--;
   }
   else
   {
       putback(a);
       arr[b.y][top[b.y]]=a.val;
       arr[a.y][--top[a.y]]=-1;
       top[b.y]++;
   }
}
void pil(point a,point b)
{
    int i,j;
    for(i=a.x,j=top[b.y];arr[a.y][i]!=-1;i++,j++)
    {
        arr[b.y][j]=arr[a.y][i];
        arr[a.y][i]=-1;
        top[a.y]--;
        top[b.y]++;
    }
}
void dopilon(point a,point b)
{
   if(top[b.y]==1)
   {
      pil(a,b);
   }
   else
   {
      putback(b);
      pil(a,b);
   }
}
void dopilov(point a,point b)
{
   pil(a,b);
}
int main(int argc, char* argv[])
{
   int n;
   point tp1,tp2;
   char op1[10],op2[10];
   int num,num1;
   scanf("%d",&n);
   init(n);
   scanf("%s",&op1);
   while(1)
   {
       if(op1[0]=='q') break;
       scanf("%d %s %d",&num,&op2,&num1);
       tp1=findp(n,num);
       tp2=findp(n,num1);
       if(tp1.y==tp2.y){ scanf("%s",&op1);continue;}
       if(op1[0]=='m')
       {
          if(op2[1]=='n')
          {
             domovon(tp1,tp2);
             
          }
          else
          {
             domovov(tp1,tp2);

          }
       }
       else
       {
          if(op2[1]=='n')
          {
             dopilon(tp1,tp2);

          }
          else
          {
             dopilov(tp1,tp2);

          }
       }
       scanf("%s",&op1);
   }
   pr(n);
        return 0;
}
