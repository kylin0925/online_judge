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
    string s;
    string chmap="eqdaczrwfsvxtegdbcyrhfnvutjgmbiykh,noulj.mpi;k[o'l]p";
    string ans = "";
    
    while(getline(cin,s)) {
    
        for(int i = 0 ; i < s.length(); i++){
            //cout<<"??? "<<s[i]<<"\n";
            for(int j = 0;j<chmap.length() ;j+=2){
                //cout<<"??? "<<chmap[j] << " " << chmap.length()<<"\n";
                if(s[i]==' '){
                    ans+=' ';
                    break;
                }
                if(s[i] == chmap[j]){
                    ans+=chmap[j+1];
                }
                else if(tolower(s[i]) == chmap[j]){
                    ans+=chmap[j+1];
                }
            }
        }
        cout<<ans<<"\n";
        ans="";
    }
    return 0;
}