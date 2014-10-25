/* @JUDGE_ID: 53xxxx 145 C++ */
#include <stdio.h>
#include <string.h>

float charst[5][3]={{0.10,0.06,0.02},
                    {0.25,0.15,0.05},
                    {0.53,0.33,0.13},
                    {0.87,0.47,0.17},
                    {1.44,0.80,0.30}};
float rate;
int  a,b,c;
int  ahour,amin,bhour,bmin;
int tamin,tbmin;
char buff[100];
void count(int n)
{
   tamin=ahour*60+amin;
   tbmin=bhour*60+bmin;
   if(tbmin<=tamin) tbmin+=(24*60);
   if((tamin>=0 && tamin <480)&&(tbmin>=0 && tbmin <480))
   {
      a=b=0;c=tbmin-tamin;
      rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=0 && tamin <480)&&(tbmin>=480 && tbmin <1080))
   {
      a=tbmin-480;b=0;c=480-tamin;
      rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=0 && tamin <480)&&(tbmin>=1080 && tbmin <1320))
   {
      a=600;b=tbmin-1080;c=480-tamin;
      rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=0 && tamin <480)&&(tbmin>=1320 && tbmin <1920))
   {
      a=600;b=240;c=480+tbmin-tamin-1320;
      rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=480 && tamin<1080)&&(tbmin>=480 && tbmin<1080))
   {
       a=tbmin-tamin; b=0;c=0;
       rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=480 && tamin<1080)&&(tbmin>=1080 && tbmin<1320))
   {
       a=1080-tamin; b=tbmin-1080;c=0;
       rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=480 && tamin<1080)&&(tbmin>=1320 && tbmin<1920))
   {
       a=1080-tamin; b=240;c=tbmin-1320;
       rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=480 && tamin<1080)&&(tbmin>=1920 && tbmin<2520))
   {
       a=1080-tamin+tbmin-1920; b=240;c=600;
       rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=1080 && tamin<1320)&&(tbmin>=1080 && tbmin<1320))
   {
       a=0; b=tbmin-tamin;c=0;
        rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=1080 && tamin<1320)&&(tbmin>=1320 && tbmin<1920))
   {
       a=0; b=1320-tamin; c=tbmin-1320;
       rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=1080 && tamin<1320)&&(tbmin>=1920 && tbmin<2520))
   {
       b=1320-tamin; c=600;a=tbmin-1920;
        rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=1080 && tamin<1320)&&(tbmin>=2520 && tbmin<2760))
   {
       b=1320-tamin+tbmin-2520; c=600;a=600;
        rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=1320 && tamin <1920)&&(tbmin>=1320 && tbmin<1920))
   {
       c=tbmin-tamin;a=b=0;
        rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=1320 && tamin <1920)&&(tbmin>=1920 && tbmin <2520))
   {
       a=tbmin-1920;b=0;c=1920-tamin;
        rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=1320 && tamin <1920)&&(tbmin>=2520 && tbmin <2760))
   {
       a=600;b=tbmin-2520;c=1920-tamin;
       rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
   else if((tamin>=1320 && tamin <1920)&&(tbmin>=2760 && tbmin <2880))
   {
       a=600;b=240;c=1920-tamin+tbmin-2760;
       rate=a*charst[n][0]+b*charst[n][1]+c*charst[n][2];
   }
}
int main(int argc, char* argv[])
{
    char *s,*pno;

    while(1)
    {
       gets(buff);
       
       s=strtok(buff," ");
       if(s[0]=='#') break;
       pno=strtok(NULL," ");
       sscanf(strtok(NULL," "),"%d",&ahour);
       sscanf(strtok(NULL," "),"%d",&amin);
       sscanf(strtok(NULL," "),"%d",&bhour);
       sscanf(strtok(NULL," "),"%d",&bmin);


       if(s[0]=='A')count(0);
       else if(s[0]=='B') count(1);
       else if(s[0]=='C') count(2);
       else if(s[0]=='D') count(3);
       else if(s[0]=='E') count(4);
       printf("%s %d %d %d %c %.2f\n",pno,a,b,c,s[0],rate);
    }
        return 0;
}
 
