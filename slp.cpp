#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1005];
int ce[1001],vs[1001];
void bfsdq(int u){
	vs[u]=1;
	queue<int> q;
	q.push(u);
	while(q.size()){
		int top=q.front();q.pop();
		for(int x: ke[top]){
			if(!vs[x]){
				vs[x]=1; ce[x]=top; q.push(x);
			}
		}
	}
}
int main(){
	int t;cin >> t;
	while(t--){
		int n,m,s;
		memset(ce,0,sizeof(ce));
		memset(vs,0,sizeof(vs));
		cin >> n >> m >> s;
		for(int i=1;i<=m;i++){
			int x,y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		bfsdq(s);
		for(int i=1;i<=n;i++){
			if(i!=s){
				if(vs[i]!=0){
					stack<int> st;
					st.push(i);
					int temp=ce[i];
					while(temp!=s){
						st.push(temp); temp=ce[temp];
					}
					st.push(s);
					while(st.size()) {
					cout << st.top() << " " ; st.pop();}
					cout << endl;
				}
				else cout << "No path" << endl;
			}
		}
	}
}
