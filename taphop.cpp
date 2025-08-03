#include<bits/stdc++.h>
using namespace std;
int n,k,s,dem=0,tong=0;
vector<int> v;
void in(){
	for(int i=0;i<v.size();i++) cout << v[i] << " ";
	cout << endl;
}
void ql(int i){
	for(int j=i+1;j<=n;j++){
		if(tong<s){
			v.push_back(j);
			tong+=j;
			if(v.size()==k){
				if(tong==s) dem++;
			} else ql(j);
			v.pop_back();
			tong-=j;
		}
	}
}
int main(){
	n=1;k=1;s=1;
	while(n!=0&&s!=0&&k!=0){
		cin >> n >> k >> s;
	    ql(0);
	cout << dem  << endl; dem=0;
	}
}
