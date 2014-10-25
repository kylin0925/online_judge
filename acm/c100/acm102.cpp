/*@JUDGE_ID:53xxxx  102 C*/
/*@BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
void main()
{
 int s[3][3];
 int b,g,c,con,i,j,sum=0,dsum,max=-1;
 char out[]="abc ";
 while(scanf("%d %d %d %d %d %d %d %d %d",&s[0][0],&s[0][1],&s[0][2],&s[1][0],&s[1][1],&s[1][2],&s[2][0],&s[2][1],&s[2][2])==9)
 {
      max=-1;
      sum=0;
      for(i=0;i<3;i++)
      {
          for(j=0;j<3;j++){ sum+=s[i][j]; }
      }
      for(b=0;b<3;b++)
      {
            for(c=0;c<3;c++)
            {
               if(b==c) continue;
                 for(g=0;g<3;g++)
                 {
                   if(b==g||g==c) continue;
                   dsum=s[b][0]+s[g][1]+s[c][2];
                   if(max<dsum)
                   {
                         max=dsum;
                         con=sum-max;
                         out[b]='B';
                         out[c]='C';
                         out[g]='G';
                   }
                 }
             }
         }
      printf("%s%d\n",out,con);
   }
}
/*@END_OF_SOURCE_CODE*/
