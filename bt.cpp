#include <bits/stdc++.h>
using namespace std;
int a[100][100],n,vs[100],ce[100];
vector<pair<int,int>> v;
void openfile(){
  freopen("CK.INP","r",stdin);
  freopen("CK.OUT","w",stdout);
}
void dfs(int u){
	vs[u]=1;
	for(int i=1;i<=n;i++){
		if(!vs[i]&&a[u][i]==1){ 
			ce[i]=u; 
		    v.push_back({u,i});
		    dfs(i);
		}
	}
}
void bfs(int u){
	queue<int> q;
	q.push(u);vs[u]=1;
	while(q.size()){
		int top=q.front();q.pop();
		for(int i=1;i<=n;i++){
			if(!vs[i]&&a[top][i]==1){ 
			    v.push_back({top,i});
				vs[i]=1;ce[i]=u;q.push(i);
			}
		}
	}
}
int main(){
    openfile();
	int t,u;cin >> t >> n >> u;
	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cin >> a[i][j];
    }   
	if(t==1){
		dfs(u);
		if(v.size()==n-1){
			cout << n-1 << endl;
			for(int i=0;i<v.size();i++) cout << v[i].first << " " << v[i].second << endl;
		} else cout << 0 << endl;
	}
	else {
		bfs(u);
		if(v.size()==n-1){
			cout << n-1 << endl;
			for(int i=0;i<v.size();i++) cout << v[i].first << " " << v[i].second << endl;
		} else cout << 0 << endl;
	}
}
