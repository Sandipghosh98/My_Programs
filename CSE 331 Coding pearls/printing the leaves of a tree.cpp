#include<bits/stdc++.h>
#include <queue> 
using namespace std;
	struct node{
		int data;
		node *left, *right;
		
	}*root=NULL;
	node *newNode(int data){
		node* newnode= new node;
		newnode->data=data;
		newnode->left=newnode->right=NULL;
		return newnode;
	}
	int arr[20];
	int co=0;
	
		void inorder(node *ro){
	if(ro==NULL)
		return;
		
	
		inorder(ro->left);
		if(ro->left==NULL && ro->right==NULL){
		
			cout<<ro->data<<" ";
			arr[co]=ro->data;
			co++;
		}
		inorder(ro->right);
		
		
	}
	int main(){

root=newNode(10);
root->left=newNode(20);
root->right=newNode(30);
root->right->left=newNode(60);
root->left->left=newNode(40);
root->left->right=newNode(50);
inorder(root);
int e;
cout<<"enter the node "<<endl;
cin>>e;
for(int i=0;i<co;i++){
	
	if(e==arr[i]){
		if((co-1)==i){
		
			cout<<"-1";
			exit(0);}
			
		cout<<arr[i+1];
		
	}
}





}
