#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long arr[N];
int n, M;
bool func(int mid){

    long long sum = 0;

    for(int i = 0; i < n; i++){
        if((arr[i] - mid)>0){
            sum += arr[i] - mid;
        }
    }
	return (sum >= M);
}

int main(){

	cin >> n >> M;
	for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int lo = 0 , hi = 1e9, mid;
    while(hi - lo > 1){
        mid = (hi + lo) >> 1;
        if(func(mid)){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    if(func(hi)){
        cout << hi << endl;
    }
    else{
        cout << lo << endl;
    }
	
	
}