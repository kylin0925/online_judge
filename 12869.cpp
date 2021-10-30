#include <iostream>
#include <string>
unsigned long long gcd(unsigned long long m,unsigned long long n){    
    return n==0? m : gcd(n,m%n);
}
unsigned long long int lcm(unsigned long long a,unsigned long long b){
    return (a/gcd(a,b))*b;
}
using namespace std;
int main(int argc,char** argv){
    unsigned long long int a,b;
    
    while(cin>>a>>b) {
        if(a==0 && b == 0)
            break;
        unsigned long long int l = (unsigned long long int)(a/5);
        unsigned long long int h = (unsigned long long int)(b/5);
        cout<< h-l+1<<"\n";

    }
    return 0;
}