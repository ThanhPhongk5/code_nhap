#include<bits/stdc++.h>
using namespace std;
int n;
string a;
void in(){
    cout << a ;
}
int sinh(){
    int i=n-2;
    while(i>=0&&a[i]>=a[i+1]) i--;
    if(i==-1) return 0;
    else {
        int k=n-1;
        while(a[k]<=a[i]) k--;
        swap(a[k],a[i]);
        int l=i+1,r=n-1;
        while(l<r){
        swap(a[l],a[r]);
        l++;r--;
        }
        return 1;
    }
}
int main(){
	int t;
	cin >> t;
    for(int j=1;j<=t;j++){
    	int x;cin >> x;
    	cin >> a;
    	cout << x << " ";
    	n=a.size();
    	if(sinh()) {
    		in();
		} else cout << "BIGGEST";
		cout << endl;
	}
}
