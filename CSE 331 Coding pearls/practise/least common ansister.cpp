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

node* lca(node* root,int a,int b){
	if(root==NULL){
		return NULL;
	}
	else if(a>root->data && b>root->data)
	{
		lca(root->right,a,b);
		
	}
	else if(b<root->data && a<root->data){
		
		lca(root->left,a,b);
	}
	
	
}


	
int main(){
	int arr[]={5,3,4,7,6,8,2,9};
	int n=8;
	int val;
	node* root=newNode(arr[0]);
//	node* root1=makeBST(arr,1,n-1,root);
	for(int i=1;i<n;i++){
	val=arr[i];
	makeBST(root,val);
		
	
	

}
	inorder(root);
	int a,b;
	cout<<endl;
	cin>>a>>b;
	lca(root,a,b);		//least common ansister
	
}
