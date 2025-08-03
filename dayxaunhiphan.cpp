#include<bits/stdc++.h>
using namespace std;
long long f[100];
void kt(){
	f[1]=1,f[2]=1;
	for(int i=3;i<=92;i++) f[i]=f[i-1]+f[i-2];
}
int giai(long long n, long long k){
	if(n==1) return 0;
	if(n==2) return 1;
	if(k<=f[n-2]) return giai(n-2,k);
	else return giai(n-1,k-f[n-2]);
}
int main(){
	int t; cin >> t;
	kt();
	while(t--){
		long long n,k;
		cin >> n >> k;
		cout << giai(n,k) << endl;
	}
}
