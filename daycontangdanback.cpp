#include<bits/stdc++.h>
using namespace std;
int n,k,dem;
int a[1005];
vector<int> v;
void in(){
	for(int i=0;i<v.size();i++) cout << v[i] << " ";
	cout << endl;
}
void ql(int i){
	for(int j=i+1;j<=n;j++){
		if(a[j]>a[i]){
		v.push_back(a[j]);
		if(v.size()==k) dem++;
		else ql(j);
		v.pop_back();
		}
	}
}
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	ql(0);
	cout << dem;
}
