#include<bits/stdc++.h>
using namespace std;
vector<char> v;
vector<vector<char>> vv;
int n,k,d=0;
char a[2];
bool check(){
	int dem=0;
	for(int i=0;i<n;i++){
		int temp=0;
		while(v[i]=='A'){
			temp++;i++;
		}
		if(temp==k) dem++;
	}
	return dem==1;
}
void in(vector<char> v){
	for(int i=0;i<n;i++) cout << v[i] ;
	cout << endl;
}
void ql(int i){
	for(int j=0;j<=1;j++){
		v.push_back(a[j]);
		if(v.size()==n){
			if(check()){
				d++; vv.push_back(v);
			}
		}
		else ql(i+1);
		v.pop_back();
	}
}
int main(){
	a[0]='A';a[1]='B';
	cin >> n >> k;
	ql(0);
	cout << d << endl;
	for(int i=0;i<vv.size();i++) in(vv[i]) ;
}
