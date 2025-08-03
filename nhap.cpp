#include<bits/stdc++.h>
using namespace std;
int vs[1001];
vector<int> ke[1005];
int main(){
	int t;
	cin >> t;
	while(t--){
		memset(vs,0,sizeof(vs));
		int n,m,u;
		cin >> n >> m >> u;
		vector<pair<int,int>> v;
		while(m--){
			int x,y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		queue<int> q;
		q.push(u);
		vs[u]=1;
		while(q.size()){
			int top=q.front(); q.pop();
			for(int x: ke[top]){
				if(!vs[x]){
					vs[x]=1;
					v.push_back({top,x});
					st.push(x);
				}
			}
		}
		if(v.size()==n-1) {
			for(auto i:v) cout << i.first << " " << i.second << endl;
		} else cout << "-1" << endl;
		v.clear();
		for(int i=1;i<=n;i++) ke[i].clear();
	}
}
