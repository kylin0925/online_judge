/* @JUDGE_ID: 53xxxx 486 C++ */
#include <stdio.h>
#include <string.h>
char buff[1000];
char *tmp;
long sum;
long table[40];
int n;
int tra(char tmp[])
{
    if(!strcmp("negative",tmp)){n=-1;return -1;}
    else if(!strcmp("zero",tmp)){return 0;}
    else if(!strcmp("one",tmp)){return 1;}
    else if(!strcmp("two",tmp)){return 2;}
    else if(!strcmp("three",tmp)){return 3;}
    else if(!strcmp("four",tmp)){return 4;}
    else if(!strcmp("five",tmp)){return 5;}
    else if(!strcmp("six",tmp)){return 6;}
    else if(!strcmp("seven",tmp)){return 7;}
    else if(!strcmp("eight",tmp)){return 8;}
    else if(!strcmp("nine",tmp)){return 9;}
    else if(!strcmp("ten",tmp)){return 10;}
    else if(!strcmp("eleven",tmp)){return 11;}
    else if(!strcmp("twelve",tmp)){return 12;}
    else if(!strcmp("thirteen",tmp)){return 13;}
    else if(!strcmp("fourteen",tmp)){return 14;}
    else if(!strcmp("fifteen",tmp)){return 15;}
    else if(!strcmp("sixteen",tmp)){return 16;}
    else if(!strcmp("seventeen",tmp)){return 17;}
    else if(!strcmp("eighteen",tmp)){return 18;}
    else if(!strcmp("nineteen",tmp)){return 19;}
    else if(!strcmp("twenty",tmp)){return 20; }
    else if(!strcmp("thirty",tmp)){return 30;}
    else if(!strcmp("forty",tmp)){return 40;}
    else if(!strcmp("fifty",tmp)){return 50;}
    else if(!strcmp("sixty",tmp)){return 60;}
    else if(!strcmp("seventy",tmp)){return 70;}
    else if(!strcmp("eighty",tmp)){return 80;}
    else if(!strcmp("ninety",tmp)){return 90;}
    else if(!strcmp("hundred",tmp)){return 100;}
    else if(!strcmp("thousand",tmp)){return 1000;}
    else if(!strcmp("million",tmp)){return 1000000;}

}
int main(int argc, char* argv[])
{
    int i,coun,t;
    int m,th,z;
    while(gets(buff))
    {
      for(i=0;i<40;table[i]=0,i++);
      i=0;
       sum=0;
       n=1;
       coun=1;
       tmp=strtok(buff," ");
        while(tmp!=NULL)
        {
           t=tra(tmp);
           if(t!=-1)
           {
            table[i++]=tra(tmp);
            coun++;
           }
           tmp=strtok(NULL," ");
        }
        i=0;
        m=th=0;
        while(i<coun)
        {
              if(table[0]==0){sum=0;break;}
              if(table[i]<100){sum+=table[i];}
              else if(table[i]==100){sum*=100;}
              else if(table[i]==1000){th=sum*1000;sum=0;}
              else if(table[i]==1000000){m=sum*1000000;sum=0;}
              i++;
        }
         printf("%ld\n",n*(m+th+sum));
    }
        return 0;
}
