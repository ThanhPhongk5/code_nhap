#include<bits/stdc++.h>
using namespace std;
int a[1001],n,ok=1;
void in(){
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << endl;
}
void sinh(){
    int i=n-1;
    while(a[i]>a[i+1]) i--;
    if(i==0) ok=0;
    else {
        int k=n;
        while(a[k]<a[i]) k--;
        swap(a[k],a[i]);
        int l=i+1,r=n;
        while(l<=r){
            swap(a[l],a[r]);
            l++;r--;
        }
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++) a[i]=i;
    while(ok){
        in();
        sinh();
    }
}