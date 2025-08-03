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
void insert(Node* root,int n1,int n2,char c){
	if(root==NULL) return;
	if(root->data==n1){
		if(c=='R') root->right=new Node(n2);
		else root->left=new Node(n2);
	}
	else {
		insert(root->left,n1,n2,c);
		insert(root->right,n1,n2,c);
	}
}
bool kt(Node* root){
	queue<pair<Node*,int>> q;
	q.push({root,0});
	int la=-1,ht;
	while(q.size()){
		pair<Node* ,int> t=q.front();q.pop();
		Node* t1=t.first; int t2=t.second;
		if(t1->left==NULL&&t1->right==NULL){
			if(la==-1){
				ht=t2; la=1;
			} else if(t2!=ht) return false;
		}
		if(t1->left) q.push({t1->left,t2+1});
		if(t1->right) q.push({t1->right,t2+1});
	}
	return true;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,n1,n2;
		char c;
		cin >> n ;
		Node* root=NULL;
		while(n--){
				cin>> n1 >> n2 >> c;
				if(root==NULL){
					root=new Node(n1);
					if(c=='L') root->left=new Node(n2);
					else root->right=new Node(n2);
				}
				else insert(root,n1,n2,c);
		}
		if(kt(root)) cout << "1" << endl;
		else cout << "0" << endl;
	}
}
