#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,n1,n2;
	cin >> n >> n1 >> n2;
	int a[n],d[n],t[n],max1=-1e9,max2=1;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		d[i]=1; t[i]=a[i];
	}
	for(int i=1;i<n;i++){
		if(t[i]<t[i-1]+a[i]) {
			t[i]=t[i-1]+a[i]; d[i]=d[i-1]+1;
		}
	}
	for(int i=0;i<n;i++){
		if(t[i]>max1&&d[i]<=n2&&d[i]>=n1){
			max1=t[i]; max2=d[i];
		}
	}
	cout << max1 << endl;
}
