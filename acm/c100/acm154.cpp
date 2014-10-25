/* @JUDGE_ID: 53xxxx 154 C++ */
#include <stdio.h>
#include <string.h>
int map[150][10];
char tcity[30];
int  c;
int tres[10][10],res[10];
int wone(char *tmp)
{
    if(tmp[2]=='P')  return 0;
    if(tmp[2]=='G')  return 1;
    if(tmp[2]=='S')  return 2;
    if(tmp[2]=='A')  return 3;
    if(tmp[2]=='N')  return 4;
}
void dset(char *tmp)
{
    if(tmp[0]=='r')  map[c][0]=wone(tmp);
    if(tmp[0]=='o')  map[c][1]=wone(tmp);
    if(tmp[0]=='y')  map[c][2]=wone(tmp);
    if(tmp[0]=='g')  map[c][3]=wone(tmp);
    if(tmp[0]=='b')  map[c][4]=wone(tmp);
}
void set()
{
    char *tmp;
    int j=0;
    tmp=strtok(tcity,",");
    dset(tmp);
    while(tmp!=NULL)
    {
       tmp=strtok(NULL,",");
       if(tmp==NULL) break;
       dset(tmp);
    }
}
void det()
{
   int i,j,k,m,p,t;
   for(i=0,m=9999;i<c;i++)
   {
       for(j=0,t=0;j<c;j++)
       {
         for(k=0;k<5;k++)
         {
          if(i!=j)
          {
           if(map[i][k]!=map[j][k]) t++;
          }
         }
       }
       if(t<m) m=t,p=i;
   }
   printf("%d\n",p+1);
}
int main(int argc, char* argv[])
{
   int i,j;
   while(1)
   {
       for(i=0;i<10;map[0][i]=0,i++);
       scanf("%s",&tcity);
       c=0;
       if(tcity[0]=='#') break;
       set();
       c++;
       while(1)
       {
          scanf("%s",tcity);
          if(tcity[0]=='e') break;
          set();
          c++;
       }
       det();
   }
        return 0;
}
