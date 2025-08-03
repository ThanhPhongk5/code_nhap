#include<bits/stdc++.h>
using namespace std;
int dem=0;
vector<string> v;
void solocphat(int n){
	queue<string> q;
	q.push("6");
	q.push("8");
	while(q.size()){
		string s=q.front();q.pop();
		v.push_back(s);
		dem++;
		if(s.size()<=n-1){
			q.push(s+"6");
			q.push(s+"8");
		} else break;
	}
	while(q.size()){
		v.push_back(q.front());q.pop(); dem++; 
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;cin >> n;
		solocphat(n);
		cout << dem << endl;
		for(int i=0;i<v.size();i++) cout << v[i] << " ";
		cout << endl;
		dem=0; v.clear();
 	}
}
