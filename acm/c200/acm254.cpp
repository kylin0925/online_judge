/* @JUDGE_ID: 53xxxx 254 C++ */
#include <stdio.h>
#include <string.h>
int n;
char cmove[150];
char bcode[150];
int p[3],disk[150];
void big_dtob()
{
    int r,len,b=0,blen=0,i,bb;
    char da[150];
    len=strlen(cmove);
    while(1)
    {
        r=0;
        for(i=0,blen=0,bb=0;i<len;i++)
        {
              da[i]=((cmove[i]-'0'+r*10)/2)+'0';
              r=(cmove[i]-'0'+r*10)%2;
              blen++;
        }
        da[blen]='\0';
        bcode[b++]=r+'0';
        strcpy(cmove,da);
        len=strlen(cmove);
        for(i=0;i<len;i++){if(da[i]=='0') bb++;}
        if(bb==len && da[len-1]=='0') break;
    }
}
int main(int argc, char* argv[])
{
    int len,i,pbit;
    while(scanf("%d %s",&n,&cmove)==2)
    {
       for(i=0;i<150;bcode[i]='\0',i++);
       p[0]=p[1]=p[2]=0;
       pbit=-1;
       if(n==0) break;
       for(i=0;i<150;disk[i]=0,i++);
       big_dtob();
       len=strlen(bcode);
       for(i=len;i<n;bcode[i]='0',i++);
       /*printf("%s\n",bcode);*/
       if(bcode[n-1]=='0'){ disk[n-1]=0;}
       else
       {
          if(n%2==1) disk[n-1]=1;
          else
            disk[n-1]=2;
       }
       for(i=n-2;i>=0;i--)
       {
          if(bcode[i]==bcode[i+1]){ disk[i]=disk[i+1];}
          else
          {
             if(n%2==1)
             {
                 if(bcode[i]=='1')
                 {
                   if(((n-i)%2)==1)
                      disk[i]=(disk[i+1]+1)%3;
                   else
                      disk[i]=(disk[i+1]+2)%3;
                 }
                 else if(bcode[i]=='0')
                 {
                    if(((n-i)%2)==1)
                      disk[i]=(disk[i+1]+2)%3;
                    else
                      disk[i]=(disk[i+1]+1)%3;
                 }
             }
             else
             {
                 if(bcode[i]=='1')
                 {
                   if(((n-i)%2)==1)
                    disk[i]=(disk[i+1]+2)%3;
                   else
                    disk[i]=(disk[i+1]+1)%3;
                 }
                 else
                 {
                   if(((n-i)%2)==1)
                    disk[i]=(disk[i+1]+1)%3;
                   else
                    disk[i]=(disk[i+1]+2)%3;
                 }
             }
          }
       }
       for(i=0;i<n;i++)
       {
           p[disk[i]]++;
       }
       printf("%d %d %d\n",p[0],p[1],p[2]);
    }
        return 0;
}
