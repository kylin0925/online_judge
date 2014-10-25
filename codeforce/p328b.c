#include <stdio.h>
#include <string.h>
/*void dump(int arr[])
{
    int i;
    for(i=0;i<10;i++)
        printf("%d ",arr[i]);
    
    printf("\n");
}*/
int main(int argc,char** argv)
{
    char innum[1000]={0};
    char testnum[1000]={0};
    char c;
    int num[100]={0};
    int map[100]={0};
    int len,len2,i,res,min=99999;
    scanf("%s",innum);
    scanf("%s",testnum);
    len=strlen(innum);

    for(i=0;i<len;i++)
    {
        c = innum[i] - '0';
        if(c==5 || c == 2)
            map[2]++;
        else if(c==9 || c == 6)
            map[6]++;
        else
            map[c] ++;
    }
    /*dump(map);*/
    len2 = strlen(testnum);
    for(i=0;i<len2;i++)
    {
        c = testnum[i]-'0';
        if(c == 5 || c == 2)
            num[2]++;
        else if(c == 9 || c == 6 )
            num[6]++;
        else
            num[c]++;
    }
    /*dump(num);*/
    for(i=0;i<10;i++)
    {
        if(map[i]){
            num[i] = num[i]/map[i];
            if(min>num[i])
                min = num[i];
        }
    }
    printf("%d\n",min);
    return 0;
}
