#include <bits/stdc++.h>
using namespace std;

int binexp1(int a, int b, int m){
	int result = 1;
	while(b>0){
		if(b & 1){
			result = (result  * 1LL * a) % m;
		}
		a = (a * 1LL * a) % m;
		b >>= 1;
	}
	return result;
}

long long multiply(long long a, long long b, long long m){
	long long result = 0;
	while(b>0){
		if(b & 1){    // b % 2 == 1
			result = result + a;
			result %= m;
		}
		a <<= 1;  // a = a * 2
		a %= m;
		b >>= 1;  // b = b / 2
	}
	return result;
}

long long binexp2(long long a, long long b, long long m){
	long long result = 1;
	while(b>0){
		if(b & 1){
			result = multiply(result, a, m);
		}
		a = multiply(a, a, m);
		b >>= 1;
	}
	return result;
}