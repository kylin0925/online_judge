/* @JUDGE_ID: 53xxxx 696 C++ */
#include <stdio.h>

void main()
{
  int col,row,t;
  while(1)
  {
      scanf("%d %d",&row,&col);
      if(!row && !col) break;
      if(col==1)
      {
 printf("%d knights may be",row);
 printf(" placed on a %d row %d column board.\n",row,col);
      }
      else if(row==1)
      {
 printf("%d knights may be",col);
 printf(" placed on a %d row %d column board.\n",row,col);
      }
      else if(row==2 || col==2)
      {
       t =(((row==2)?col:row)/4)*4;
       t+=(((row==2?col:row)%4)>2)?4:(((row==2?col:row)%4)*2);
 printf("%d knights may be ",t);
 printf("placed on a %d row %d column board.\n",row,col);
      }
      else
      {
 printf("%d knights may be placed",((row*col+1)/2));
 printf(" on a %d row %d column board.\n",row,col);
      }
  }
}
