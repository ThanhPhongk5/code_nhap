#include<bits/stdc++.h>
using namespace std;
int cha[1001],n,num[1001];
void kt(){
	for(int i=1;i<=n;i++) {
		cha[i]=i;
		num[i]=1;
	}
}
int Find(int u){
	if(u!=cha[u]) cha[u]=Find(cha[u]);
	return cha[u];
}
void Union(int u,int v){
	int a=Find(u),b=Find(v);
	if(a==b) return;
	if(num[a]<num[b]) swap(a,b);
	num[a]+=num[b];
	cha[b]=a;
}
int main(){
	int m,dem=0;
	cin >> n >> m;
	kt();
	for(int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		Union(x,y);
	}
	for(int i=1;i<=n;i++) if(i==cha[i]) dem++;
	cout << dem << endl;
}
