#include<bits/stdc++.h>
using namespace std;
int a[1001],n,k,ok=1;
void in(){
    for(int i=1;i<=k;i++) cout << a[i] << " ";
    cout << endl;
}
void sinh(){
    int i=k;
    while(a[i]==n-k+i){
        i--;
    }
    if(i==0) {
        ok=0; return;
    }
    a[i]=a[i]+1;
    for(int j=i+1;j<=k;j++){
        a[j]=a[i]+j-i;
    }
}
int main(){
    cin >> n >> k;
    for(int i=1;i<=k;i++) a[i]=i;
    while(ok){
        in();sinh();
    }
}