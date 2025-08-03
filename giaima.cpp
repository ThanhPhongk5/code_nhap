#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
       string s;
       cin >> s;
       int f[50];
       f[0]=1;
       f[1]=1;
       for(int i=2;i<=s.size();i++){
       	 f[i]+=f[i-1];
        int twoDigit = stoi(s.substr(i - 2, 2));
        if (twoDigit >= 10 && twoDigit <= 26) {
            f[i] += f[i - 2];
        }
    
       }
       cout << f[s.size()] << endl;
    }
}
