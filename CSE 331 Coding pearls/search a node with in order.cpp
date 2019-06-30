#include<bits/stdc++.h>
#include <queue> 
using namespace std;

	struct node{
		int data;
		node *left, *right;
		
	}*root=NULL,*p;
	node *newNode(int data){
		node* newnode= new node;
		newnode->data=data;
		newnode->left=newnode->right=NULL;
		return newnode;
	}
	int c=0,k=3;
		void inorder(node *ro ){
	if(ro==NULL)
		return;
		//	cout<<ro->data<<" ";
		if(c<=k){
		
		inorder(ro->left);
		c++;
		if(c==k){
			cout<<ro->data<<" ";
			return;
		}
		inorder(ro->right);
}
}
	int main(){
		root=newNode(10);
		root->left=newNode(20);
root->right=newNode(30);
root->left->left=newNode(40);
//root->left->right=newNode(50);
root->right->left=newNode(50);
root->right->left->right=newNode(60);
inorder(root);

}
