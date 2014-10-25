#include <iostream.h>

#define MDiv (1000)

long Dtable[MDiv][2];
int isPrime(long x){
	long i;
	if (x&1) {
		for(i=3;i*i<=x;i+=2){
			if (!(x % i)) return 0;
		}
	}
	else return 0;
	return 1;
}

int GCD(int a,int b){
	if (!(a % b)) return b;
	else return GCD(b,a % b);
}

long mypow(long x,int y){
	long temp;
	if (y==0) return 1;
	else if (y % 2) return x*mypow(x,y-1);
	else{
		temp=mypow(x,y/2);
		return temp*temp;
	}
}

void OutputAnswer(long hStacknow,long nnxtHat){
	long notWork=0;
	long hStack=0;
	long nStacknow=1;

	for(;hStacknow!=1;hStacknow/=(nnxtHat+1),nStacknow*=nnxtHat){
		notWork+=nStacknow;
		hStack+=(nStacknow*hStacknow);
	}
	hStack+=(nStacknow*hStacknow);

	cout << notWork << ' ' << hStack << endl;
}

void Solve (long hFirst,long nLast){

	int gcd=-1;
	int todiv=2;
	int ndiv=0;
	int temp;
	int i;
	int nNow;
	long hFirstback=hFirst;

	if (hFirst==1 && nLast==1){

		cout << 0 << ' ' << 1 << endl;
		return;

	}
	for(temp=0;hFirst!=1;temp=0,todiv++){
		if (!(hFirst % todiv)){
			ndiv++;
			while (!(hFirst % todiv)){
				hFirst/=todiv;
				temp++;
			}
			Dtable[ndiv-1][0]=todiv;
			Dtable[ndiv-1][1]=temp;
			if (gcd==-1) gcd=temp;
			else gcd=GCD(gcd,temp);
		}
	}
	for(temp=gcd,nNow=1;temp>0;temp--,nNow=1){
		if (!(gcd % temp)){
			for(i=0;i<ndiv;i++){
				nNow*=mypow(Dtable[i][0],Dtable[i][1]/temp);
			}
			if (mypow(nNow-1,temp)==nLast){
				OutputAnswer(hFirstback,nNow-1);
				break;
			}
		}
	}
}

int main(void){
	long hFirst, nLast;
	for(cin >> hFirst >> nLast;hFirst!=0 && nLast!=0;cin >> hFirst >> nLast)
		Solve (hFirst,nLast);
	return 0;
}

/* @END_OF_SOURCE_CODE */
