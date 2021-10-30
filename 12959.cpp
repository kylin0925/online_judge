#include <iostream>

unsigned long long gcd(unsigned long long m,unsigned long long n){    
    return n==0? m : gcd(n,m%n);
}
unsigned long long int lcm(unsigned long long a,unsigned long long b){
    return (a/gcd(a,b))*b;
}

int main(int argc,char** argv){
    int j,r;
    int point[500*500]={0};
    int idx = 0;
    int p,maxpoint=-1,winner=-1;
    while(std::cin>>j>>r){
        maxpoint=-1,winner=-1;
        idx = 0;
        for(int i = 0 ; i < j * r; i++){
            //std::cout<<maxpoint<<" " << winner << "\n";
            std::cin>>p;            
            point[idx]+=p;
            if(point[idx] >= maxpoint){
                maxpoint = point[idx];
                winner = idx;
            }
            
            idx = (idx+1) % j;
        }
        std::cout<<winner+1<<"\n";
        for(int i = 0 ; i < j * r; i++)
            point[i]=0;
    }
    return 0;
}