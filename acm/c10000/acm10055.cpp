/* @JUDGE_ID: 53xxxx 10055 C++ */
/*@begin_of_source_code*/
#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
    long double a,b;
    while(scanf("%Lf %Lf",&a,&b)==2)
    {
         printf("%.0Lf\n",(long double)fabs(a-b));
    }
        return 0;
}
/*@end_of_source_code*/
