#include<bits/stdc++.h>
using namespace std;
int giai(string s){
	stack<char> st;
	int mo=0,dong=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='(') {
			mo++; st.push(s[i]);
		}
		else {
			if(mo!=0&&st.top()=='('){
				mo--;st.pop();
			}
			else {
				st.push(s[i]);
				dong++;
			}
		}
	}
	return dong/2+mo/2+dong%2+mo%2;
}
int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s; 
		getline(cin,s);
		cout << giai(s) << endl;
	}
}
