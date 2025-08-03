#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* right,*left;
	Node(int x){
		data=x;
		right=left=NULL;
	}
};
void insert(Node*& root,int n){
	if(root==NULL){
		root=new Node(n);
	}
	if(root->data>n) insert(root->left,n);
	if(root->data<n) insert(root->right,n);
}
void nodela(Node* root){
	if(root==NULL) return;
	if(root->right==NULL&&root->left==NULL) cout << root->data << " ";
	if(root->left) nodela(root->left);
	if(root->right) nodela(root->right);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		Node* root=NULL;
		for(int i=0;i<n;i++){
			int x;cin >> x;
			insert(root,x);
		}
		nodela(root);
		cout << endl;
	}
}
