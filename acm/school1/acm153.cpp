/* @JUDGE_ID: 53xxxx 153 C++ */
#include <stdio.h>
#include <string.h>
long double coun=0;
char str[100],cap,tmp[100];
long double cal(int l,char buff[])
{
  int la[100]={0},i,j;
  long double sum=1;
  for(i=0;i<100;i++){la[i]=0;}
  for(i=l,j=1;i>0;i--,j++)
  {
      sum=(sum*i)/(++la[buff[j]-'a']);
  }

  return sum;
}
void sort()
{
    int i,j;
    if(strlen(tmp)==0) return;
    for(i=0;i<strlen(tmp)-1;i++)
    {
         for(j=strlen(tmp)-1;j>i;j--)
         {
            if(tmp[j]<tmp[j-1])
            {
               cap=tmp[j];
               tmp[j]=tmp[j-1];
               tmp[j-1]=cap;
            }
         }
    }
}
int main()
{

   int  nd[100];
   int i,j,len;
   while(scanf(" %s",str)==1)
   {

        if(str[0]=='#') break;
        strcpy(tmp,str);
         coun=0;
        for(i=0;i<100;i++){nd[i]=0;}
        sort();
        while(strlen(tmp)>0)
        {

          len=strlen(tmp);
          for(j=0;tmp[j]!=str[0];j++)
          {

            if(!nd[tmp[j]-'a'])
            {
            nd[tmp[j]-'a']=1;
            cap=tmp[0]; tmp[0]=tmp[j];tmp[j]=cap;
            coun+=cal(len-1,tmp);
            cap=tmp[0]; tmp[0]=tmp[j];tmp[j]=cap;
            }
          }
          cap=tmp[0]; tmp[0]=tmp[j];tmp[j]=cap;
          for(j=0;j<strlen(tmp);j++)
          {
              tmp[j]=tmp[j+1];
              str[j]=str[j+1];
          }
          sort();

          for(j=0;j<100;j++){nd[j]=0;}

        }
        printf("%10.0Lf\n",coun+1);
   }
   return 0;
}
