#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],c[1001][1001],m,n;
void xuly(){
	memset(c,-1,sizeof(c));
	c[1][1]=0;
	queue<pair<int,int>> q;
	q.push({1,1});
	while(q.size()){
		pair<int,int> t=q.front();q.pop();
		int i=t.first,j=t.second;
		int x=a[i][j];
		if(c[i+x][j]==-1){
			q.push({i+x,j}); c[i+x][j]=c[i][j]+1;
		}
		if(c[i][j+x]==-1){
			q.push({i,j+x}); c[i][j+x]=c[i][j]+1;
		}
		if(c[m][n]!=-1) break;
	}
}
int main(){
	int k;cin >> k;
	while(k--){
	    cin >> m >> n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++) cin >> a[i][j];
		}
		xuly();
		cout << c[m][n] << endl;
	}
}
