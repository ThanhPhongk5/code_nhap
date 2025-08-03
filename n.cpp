#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
bool check(){
	if(v[0]!=8||v[n-1]!=6) return false;
	for(int i=0;i<n-1;i++){
		if(v[i]==v[i+1]&&v[i]==8) return false;
		if(i<=(n-4)) {
			if(v[i]==6&&v[i+1]==6&&v[i+2]==6&&v[i+3]==6) return false;
		}
	}
	return true;
}
void in(){
	for(int i=0;i<n;i++) cout << v[i] ;
	cout << endl;
}
void ql(int i){
	for(int j=6;j<=8;j+=2){
		v.push_back(j);
		if(v.size()==n) {
			if(check()) in();
		}
		else ql(i+1);
		v.pop_back();
	}
}
int main(){
	cin >> n;
	ql(1);
}
