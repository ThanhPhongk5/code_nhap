#include <bits/stdc++.h>
using namespace std;
int ans=0;
struct Node{
	int data;
	Node *right,*left;
	Node(int x){
		data=x;
		right=left=NULL;
	}
};
void insert(Node *&root,int n){
	if(root==NULL) root=new Node(n);
	if(root->data>n) insert(root->left,n);
	if(root->data<n) insert(root->right,n);
}
void tinh(Node *root){
	if(root==NULL) return;
	if(root->left!=NULL||root->right!=NULL) ans++;
    if(root->left) tinh(root->left);
	if(root->right) tinh(root->right);
	
}
int main() {
   int t;cin >> t;
   while(t--){
   	int n;
   	cin >> n;
   	int a[n];
   	Node *root=NULL;
   	for(int i=0;i<n;i++){
   		cin>> a[i];
   		insert(root,a[i]);
	}
	tinh(root);
	cout << ans << endl;
	ans=0;
   	
   }
}

