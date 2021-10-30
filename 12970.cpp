#include <iostream>

unsigned long long gcd(unsigned long long m,unsigned long long n){    
    return n==0? m : gcd(n,m%n);
}
unsigned long long int lcm(unsigned long long a,unsigned long long b){
    return (a/gcd(a,b))*b;
}

int main(int argc,char** argv){
    unsigned long long int v1,d1,v2,d2,i=1;
    while(1){
        std::cin>>v1>>d1>>v2>>d2;
        if(v1 == 0 && d1 == 0 && v2 == 0 && d2 == 0 )break;
        v1=v1*2;
        v2=v2*2;

        //std::cout << "debug 1: " << v1 << " " << v2 << " " << gcd(v1/2,v2/2) << std::endl;
        unsigned long long int l = lcm(v1,v2);        
        unsigned long long int dd1 = d1 * (l/v1);
        unsigned long long int dd2 = d2 * (l/v2);        
        unsigned long long int d = dd1+dd2;        
        unsigned long long int g = gcd(d,l);
        //std::cout<<"gcd (" << d <<" , " <<l << ") " << g<<"\n";
        std::cout<<"Case #" << i << ": ";
        if(dd1<dd2){
            std::cout << "You owe me a beer!" << "\n";
        }else{
            std::cout << "No beer for the captain." << "\n";
        }
        unsigned long long int pp = d/g;
        unsigned long long int qq = l/g;
        if(pp % qq > 0)
            std::cout<<"Avg. arrival time: "<<pp<<"/" << qq<<std::endl;
        else
            std::cout<<"Avg. arrival time: "<< pp/qq <<std::endl;
        i++;
    }
    return 0;
}