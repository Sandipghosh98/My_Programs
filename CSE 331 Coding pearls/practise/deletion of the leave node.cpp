#include<bits/stdc++.h>
using namespace std;

struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 

struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data  = data; 
    node->left  = node->right = NULL; 
    return(node); 
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
	
	
	//node temp;
		void preorder(node *ro){
	if(ro==NULL)
		return;
		/*	if(ro->left->left==NULL && ro->left->right==NULL){
				ro->left=NULL;
			}
				if(ro->right->left==NULL && ro->right->right==NULL){
				ro->right=NULL;
			}
			*/
		
			if(ro->left!=NULL && ro->right!=NULL){
					cout<<ro->data<<" ";
			
			}
		
			//	temp=ro;
		preorder(ro->left);
		preorder(ro->right);
	
}
	
	
	int main(){
		
		
		
		int arr[]={8,7,10,6,9,12};
		int n=6;
		int val;
		node* root=newNode(arr[0]);
//	node* root1=makeBST(arr,1,n-1,root);
	for(int i=1;i<n;i++){
	val=arr[i];
		makeBST(root,val); }
		
		preorder(root);
		
		
		
		
		
		
	}
