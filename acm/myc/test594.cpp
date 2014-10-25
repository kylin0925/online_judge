#include <stdio.h>
int main()
{
    long i;
    FILE *fp;
    fp=fopen("594.dat","w");
    for(i=0;i<2147483647;i++)
    {
       fprintf(fp,"%d\n",i);
    }
    /*for(i=0;i>-2147483648;i--)
    {
       fprintf(fp,"%d\n",i);
    } */
    fclose(fp);
        return 0;
}
 
