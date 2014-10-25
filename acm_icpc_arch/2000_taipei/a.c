#include <stdio.h>
#include <math.h>
int main(int argc,char** argv){
    long long int r = 0,cnt=0;
    long long int x=0,y=0;
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%lld",&r);
        cnt=0;
        for(x=1;x<=r;x++)
        {
            //y = (long long int)(sqrt(r*r-x*x));
            y = (long long int)(sqrt((r-x)*(r+x)));
            //printf("%lld\n",y);

            if(y*y + x * x < r*r){
                //printf("1 %lld\n",y);
                for(;y*y+x*x<r*r;y++);
                //printf("2 %lld\n",y);
                y--;
            }
            else if(y*y+x*x > r*r)
            {
                //printf("3 %lld\n",y);
                for(;y*y+x*x>r*r;y--);
                //printf("4 %lld\n",y);

            }

            //printf("after %lld\n",y);
            cnt+=y;
            //if(x%10000000 == 0) printf("%lld cnt %lld\n",x,cnt);
        }
        cnt = cnt*4;
        cnt += 4*r+1;
        printf("%lld\n",r);
        printf("%lld\n",cnt);
    }
    return 0;
}
