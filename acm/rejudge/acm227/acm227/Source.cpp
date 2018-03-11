/* @JUDGE_ID: 53xxxx 227 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>
char frams[10][10];
char command[1000];
int  x,y,canfig=0;
void rline(char a[])
{
 char c;
 int i=0;
 scanf("%c",&c);
 while(c!='\n')
 {
   a[i++]=c;
   scanf("%c",&c);
 }
}
int read()
{
  int i,j;
  x=0,y=0;
  char c;
  char line[10];
  for(i=0;i<5;i++)
  {
    rline(line);
    for(j=0;j<5;j++)
    {
      frams[i][j]=line[j];
    }
     if(frams[i][0]=='Z') return -1;

     for(j=0;j<5;j++)
     {
       if(frams[i][j]==' ')
       {
         x=j,y=i;
       }
     }
  }
   return 1;
}
void pp()
{
  int i,j;
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
		if(j==0)
			printf("%c", frams[i][j]);
		else
			printf(" %c",frams[i][j]);	
    }
    printf("\n");
  }

}
void movep(char m)
{
 if(m=='A'||m=='R'||m=='B'||m=='L')
 {
   if(m=='A')
   {
      if(y==0)
      {
         canfig=1;
         return;
      }
      else
      {
         frams[y][x]=frams[y-1][x];
         frams[y-1][x]=' ';
         y--;
      }
   }

   if(m=='B')
   {
      if(y==4)
      {
         canfig=1;
         return;
      }
      else
      {
         frams[y][x]=frams[y+1][x];
         frams[y+1][x]=' ';
         y++;
      }
   }
   if(m=='R')
   {
      if(x==4)
      {
         canfig=1;
         return;
      }
      else
      {
         frams[y][x]=frams[y][x+1];
         frams[y][x+1]=' ';
         x++;
      }
   }
   if(m=='L')
   {
      if(x==0)
      {
         canfig=1;
         return;
      }
      else
      {
         frams[y][x]=frams[y][x-1];
         frams[y][x-1]=' ';
         x--;
      }
   }
 }
}
int main()
{
  int n=1,i,con;
  char c='a';
  int first = 1;
  while(read()==1)
  {

    canfig=0;
    i=0;
    while(scanf("%c",&c)==1)
    {
       if(c=='0') break;
       if(c=='A'||c=='R'||c=='B'||c=='L')   command[i++]=c;
    }
    con=i ;
    for(i=0;i<con && !canfig ;i++)
    {
      c=command[i];
      if(c=='0') break;
      movep(c);
      command[i]='0';
    }
	if (!first) {
		printf("\n");
	}
    if(canfig)
    {
      printf("Puzzle #%d:\n",n);
      printf("This puzzle has no final configuration.\n");
    }
    else
    {
      printf("Puzzle #%d:\n",n);
      pp();
	  
    }
	if (first) {
		first = 0;
	}
    n++;
    scanf("%c",&c);
  }
        return 0;
}
/* END_OF_SOURCE_CODE */