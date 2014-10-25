/* @JUDGE_ID:53xxxx 587 C++ */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define del 0.7071067
double x,y,dis;
void sw(int num,char dr[])
{
     if(!strcmp(dr,"N"))
     {
         y+=num;
     }
     else if(!strcmp(dr,"S"))
     {
        y-=num;
     }
     else if(!strcmp(dr,"W"))
     {
        x-=num;
     }
     else if(!strcmp(dr,"E"))
     {
        x+=num;
     }
     else if(!strcmp(dr,"NE"))
     {
        x+=num*del;
        y+=num*del;
     }
     else if(!strcmp(dr,"SE"))
     {
        x+=num*del;
        y-=num*del;
     }
     else if(!strcmp(dr,"SW"))
     {
       x-=num*del;
       y-=num*del;
     }
     else if(!strcmp(dr,"NW"))
     {
       x-=num*del;
       y+=num*del;
     }
}
void cd(char comm[])
{
     char dr[5];
     char num[200];
     int inum;
     int i=0,j=0;
     while(comm[i]>='0'&&comm[i]<='9')
     {
         num[i]=comm[i];
         i++;
     }
     sscanf(num,"%d",&inum);
     while(i<strlen(comm))
     {
        dr[j++]=comm[i++];
     }
     dr[j]='\0';
     sw(inum,dr);
}
void main()
{
   char in[1000];
   char *tmp;
   int i,j,k,tr=1,map=1;
   long a,b;
   while(tr)
   {
       gets(in);
       x=y=0.0;
       if(!strcmp(in,"END")) break;
       in[strlen(in)-1]=',';

       tmp=strtok(in,",");
       cd(tmp);
       while(tmp!=NULL)
       {
           tmp=strtok(NULL,",");
           if(tmp!=NULL)
               cd(tmp);
       }
       dis=sqrt(x*x+y*y);
       a=x,b=y;
       if(a==-0) x=0;
       if(b==-0) y=0;
       printf("Map #%d\n",map++);
       printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
       printf("The distance to the treasure is %.3lf.\n\n",dis);
   }
}
