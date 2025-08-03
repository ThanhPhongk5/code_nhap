#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *right,*left;
	Node(int x){
		data=x;
		right=left=NULL;
	}
};
void insert(Node *root,int n1,int n2,char c){
	if(root==NULL) return ;
	if(root->data==n1){
		if(c=='L') root->left=new Node(n2);
		else root->right=new Node(n2);
	}
	else{
		insert(root->left,n1,n2,c);
		insert(root->right,n1,n2,c);
	}
}
long long tongnode(Node* root){
	if(root==NULL) return 0;
	long long tong=0;
	if(root->right&&root->right->right==NULL&&root->right->left==NULL) tong+=root->right->data;
	tong+=tongnode(root->left);
	tong+=tongnode(root->right);
	return tong;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,n1,n2;char c;
		cin >> n;
		Node* root=NULL;
		while(n--){
			cin >> n1 >> n2 >> c;
			if(root==NULL){
				root=new Node(n1);
				if(c=='L') root->left=new Node(n2);
				else root->right=new Node(n2);
			}
			else insert(root,n1,n2,c);
		}
		cout << tongnode(root) << endl;
	}
}
