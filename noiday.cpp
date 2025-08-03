#include<bits/stdc++.h>
using namespace std;
int chiphi(int a[],int n){
	priority_queue<int,vector<int>, greater<int>> q;
	long long tong=0;
	for(int i=0;i<n;i++) q.push(a[i]);
	while(q.size()>=2){
		int first=q.top();q.pop();
		int second=q.top();q.pop();
		tong+=first+second;
		q.push(first+second);
	}
	return tong;
}
int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		cout << chiphi(a,n) << endl;
	}
}
