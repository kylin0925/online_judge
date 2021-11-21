#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
unsigned long long gcd(unsigned long long m, unsigned long long n) {
	return n == 0 ? m : gcd(n, m % n);
}
unsigned long long int lcm(unsigned long long a, unsigned long long b) {
	return (a / gcd(a, b)) * b;
}
using namespace std;

#define MAX_LEN 501

unsigned long long int memo[MAX_LEN] = { 0 };
unsigned long long int MAX_INT = 2147483647;
bool check(string s) {

	return true;
}

long long int dfs(int i, string s) {
	return 0;
}

struct Point {
	double x, y;
};
// m1 * m2 =-1 if two line vertical;
// m1 = (y-y')/(x-x')
// m2 = -1/m1 = -1/(A/B) = -B/A
// (x1, y1) = (ax+bx/2,ay+by/2)
// (y-y1)/(x-x1) =m -> y-mx = y1-mx1
// (y-y1)/(x-x1)  = -B/A
// Ay -Ay1 = -Bx -(-Bx1)

// A1y +B1x = Ay1+Bx1 = e
// A2y +B2x = Ay1+Bx1 = e2
        
Point midPoint(Point a, Point b) {
	Point midP;
	midP.x = (a.x + b.x) / 2;
	midP.y = (a.y + b.y) / 2;
	return midP;
}
void sol(Point a, Point b, Point c) {
	Point midAB = midPoint(a, b);		
	double a1, b1,e;
	a1 = a.y - b.y;
	b1 = a.x - b.x;
	e = a1 * midAB.y + b1 * midAB.x;

	Point midAC = midPoint(a, c);
	double a2, b2, e2;
	a2 = a.y - c.y;
	b2 = a.x - c.x;	
	e2 = a2 * midAC.y + b2 * midAC.x;

	double D = (a1 * b2) - (b1 * a2)  ;

	double y = (e * b2 - b1 * e2  )/D;
	double x = (a1 * e2 - e * a2) / D;
	//cout << x << " " << y<<"\n";
	double r = sqrt( (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
	//cout << r << "\n";

	
	double cc, d, ee;
	cc = -2*x;
	d = -2*y;
	ee = x * x + y * y - r * r;
	
	//(x - 3.000) ^ 2 + (y + 2.000) ^ 2 = 5.000 ^ 2
	char s1, s2, s3;
	if (x < 0) {
		printf("(x + %.3lf)^2 + ", -x);
	}
	else if (x == 0) {
		printf("x^2 + ");
	}
	else {		
		printf("(x - %.3lf)^2 + ", x);
	}

	if (y < 0) {		
		printf("(y + %.3lf)^2", -y);
	}
	else if (y == 0) {
		printf("y^2", -x);
	}
	else {
		s2 = '-';
		printf("(y - %.3lf)^2", y);
	}
	//printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",s1, x, s2,y, r);
	printf(" = %.3lf^2\n", r);
	
	//x ^ 2 + y ^ 2 - 6.000x + 4.000y - 12.000 = 0
	printf("x^2 + y^2");
	if (cc > 0) {
		printf(" + %.3lfx", cc);
	}
	else if (cc < 0) {
		printf(" - %.3lfx", -cc);
	}
	if (d > 0) {
		printf(" + %.3lfy",d);
	}
	else if (d < 0) {
		printf(" - %.3lfy", -d);
	}
	if (ee > 0) {
		printf(" + %.3lf", ee);
	}
	else if (ee < 0) {
		printf(" - %.3lf", -ee);
	}
	printf(" = 0\n\n");
	//printf(" %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n", s1, cc, s2, d, s3, ee);
}

int main(int argc, char** argv) {
	Point a, b, c;
	/*a.x = 7.0f;
	a.y = -5.0f;

	b.x = -1.0f;
	b.y = 1.0f;

	c.x = 0.0f;
	c.y = -6.0f;
	sol(a, b, c);*/

	while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
		sol(a, b, c);
	}


	return 0;
}

