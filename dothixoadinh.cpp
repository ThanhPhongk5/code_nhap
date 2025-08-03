#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[1001],cha[1001],n,m;
void kt(){
	for(int i=1;i<=n;i++){
		cha[i]=i;
		num[i]=1;
	}
}
int Find(int u){
	if(u!=cha[u]) cha[u]=Find(cha[u]);
	return cha[u];
}
bool Union(int u,int v){
	int a=Find(u),b=Find(v);
	if(a==b) return false ;
	if(num[a]<num[b]) swap(a,b);
	cha[b]=a;
	num[a]+=num[b];
	return true;
}
int main(){
	cin >> n >> m;
	kt();
	int a[n+1];
	vector<int> ke[1001];
	while(m--){
			int x,y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
	}
	for(int i=1;i<=n;i++) cin >> a[i];
	int lt=0,vs[1001]={0};
	vector<string> v;
	for(int i=n;i>=1;i--){
		lt++;
		vs[a[i]]=1;
		for(int x: ke[a[i]]){
			if((vs[x]==1) &&Union(x,a[i])){
				lt--;
			}
		}
		if(lt==1) v.push_back("YES");
		else v.push_back("NO");
	}
	for(int i=v.size()-1;i>=0;i--) cout << v[i] << endl;
}
