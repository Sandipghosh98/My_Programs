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
	node *temp=NULL;
	node* findminimum(node* root){
	//	cout<<"ff";
		while (root->left != NULL)  
{  
    root = root->left;  
} 
//cout<<root->data;
	return root;
	}
	
	node* nextinorder(node *root,int data){
		if(root->data==	NULL)
			return root;
			
		
		if(root->data==data){
			if(root->right!=NULL){
				//cout<<"di"<<" ";
				node* t=root->right;
				node* r=findminimum(t);
				
			cout<<r->data;
				return r;
			}
			else{
			
			cout<<temp->data;
				return temp;
			}}
		else if(root->data > data){
				temp=root;
			//	cout<<"san"<<temp->data<<" "<<endl;
				root->left=nextinorder(root->left,data);
			}
		else{
		
		root->right=nextinorder(root->right,data);	
	}
		
		
	}


	void inorder(node *ro){
	if(ro==NULL)
		return;
		int w;
			inorder(ro->left);
			if(ro->left!=NULL && ro->right!=NULL){
				if(ro->left->data%2==0 && ro->right->data%2==0){
		cout<<ro->data<<" ";
			}}
			inorder(ro->right);
	
}


int main(){
		int arr[]={8,6,5,10,9,7,12};
	int n=7;
	int val;
	node* root=newNode(arr[0]);
//	node* root1=makeBST(arr,1,n-1,root);
	for(int i=1;i<n;i++){
	val=arr[i];
	makeBST(root,val);
}
int data;
cin>>data;
node* ans=nextinorder(root,data);
//cout<<endl<<ans->data;

}

