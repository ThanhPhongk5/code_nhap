#include <bits/stdc++.h>
using namespace std;
int a[101][101],n,vs[101],ce[101];
void dfsdq(int u){
	vs[u]=1;
	for(int i=1;i<=n;i++) if(vs[i]==0&&a[u][i]==1) dfsdq(i);
}
// kiem tra xem là do thi có chu trinh hay duong di euler ko
int check(){
	int tongle=0;
	memset(vs,0,sizeof(vs));
	dfsdq(1);
	for(int i=1;i<=n;i++) if(vs[i]==0) {
		return 0;
	}
	for(int i=1;i<=n;i++){
		int temp=0;
		for(int j=1;j<=n;j++) if(a[i][j]) temp++;
		if(temp%2==1) tongle++;
		if(tongle>2) return 0;
	}
	if(tongle) return 2;
	else return 1;
}
// lay duong di hoac chu trinh
void ceu(int a[][101],int n,int u){
	stack<int> st1,st2;
	st1.push(u);
	while(st1.size()){
		int v=st1.top(),ok=1;
		for(int i=1;i<=n;i++) if(a[v][i]) {
			st1.push(i);a[v][i]=0;a[i][v]=0;ok=0;break;
		}
		if(ok==1) {
			st2.push(v); st1.pop();
		}
	}
	while(st2.size()){
		cout << st2.top() << " ";st2.pop();
	}
}
int main(){
	int t,m,u;
	cin >> t;
	if(t==1){
		cin >> n >> m;
		for(int i=1;i<=m;i++){
			int x,y;
			cin >> x >> y;
			a[x][y]=1;a[y][x]=1;
		}
		cout << check() << endl;
	}
	else {
		cin >> n >> m >> u;
		for(int i=1;i<=m;i++){
			int x,y;
			cin >> x >> y;
			a[x][y]=1;a[y][x]=1;
		}
		ceu(a,n,u);
		cout << endl;
	}
	
}
