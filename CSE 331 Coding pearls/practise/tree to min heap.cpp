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
	vector<int>v;
	void inorder(node *ro){
	if(ro==NULL)
		return;
		int w;
			inorder(ro->left);
	
		cout<<ro->data<<" ";
			v.push_back(ro->data);
			inorder(ro->right);
	
}
int i=0;
void preorder(node *ro){
	
	if(ro==NULL)
		return;
		int w;
		ro->data=v[i++];
			preorder(ro->left);
			preorder(ro->right);
	
}
void postorder(node *ro){
	
	if(ro==NULL)
		return;
		int w;
	
			postorder(ro->left);
			postorder(ro->right);
			cout<<ro->data<<" ";
}

//for max heap just the vector be in the decending order
	int main(){
	int arr[]={8,6,5,10,9,7,12};
	int n=7;
	int val;
	node* root=newNode(arr[0]);
		for(int i=1;i<n;i++){
	val=arr[i];
	makeBST(root,val);
}
	inorder(root);
	preorder(root);
	postorder(root);
	}
