#include<bits/stdc++.h>
using namespace std;
long long solution(long long n){
	queue<long long > q;
	q.push(1);
	long long dem=0;
	while(q.size()){
		long long num=q.front();q.pop();
		if((num % n)==0) return num;
		dem++;
		q.push(num*10);
		q.push(num*10+1);
	}
}
int main(){
	int t;cin >> t;
	while(t--){
		long long n;
		cin >> n ;
		cout << solution(n) << endl;
	}
}
