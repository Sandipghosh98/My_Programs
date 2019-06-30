#include<bits/stdc++.h>
using namespace std;
#include<queue>


struct node{
	int data;
	node *left,*right;
};

node* newNode(int data){
	node* ab=new node;
	ab->data=data;
	ab->left=NULL;
	ab->right=NULL;
	return ab;
}
node* makeBST(node *ro,int v){
//	node* temp=ro;
	if(ro==NULL)
	ro=newNode(v);
	else if(ro->data<v)
	ro->right=makeBST(ro->right,v);
	else
	ro->left=makeBST(ro->left,v);
	
	return ro;
	}

	void inorder(node *ro){
	if(ro==NULL)
		return;
			inorder(ro->left);
		
			cout<<ro->data<<" ";
			inorder(ro->right);
	
}

node* findminright(node *root){
	while(root->left!=NULL)
		root=root->left;
	return root;
}

	node* del(node *root,int data){
		//cout<<l<<endl;
	if(root==NULL)
		return root;
	else if(data<root->data)
	root->left=del(root->left, data);
		else if(data>root->data)
	root->right=del(root->right, data);
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root=NULL;
		}
		else if(root->left==NULL){
			node *temp=root;
			root=root->left;
			delete temp;
		}
		else{
			node *temp=findminright(root->right);
			root->data =temp->data;
			root->right=del(root->right,temp->data);
		}
	}
	return root;
}
	
int main(){
	int arr[]={5,3,4,7,6,8};
	int n=6;
	int val;
	node* root=newNode(arr[0]);
//	node* root1=makeBST(arr,1,n-1,root);
	for(int i=1;i<n;i++){
	val=arr[i];
		makeBST(root,val);
		
	
	

}
	inorder(root);
	int d;
	cout<<endl;
	cout<<"the node you want to delete";
	cin>>d;	
	
	
	del(root,d);
	inorder(root);
}
