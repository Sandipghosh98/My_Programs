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
		queue <node *> qe;

	void labelorder(node *ro,int a[]){

	if(ro==NULL)
		return;
		qe.push(ro);
		while(!qe.empty()){
			// my testing
			node *temp= qe.front();
			qe.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL){
			 a[temp->left->data]=temp->data;
	    qe.push(temp->left); 
}
	    if(temp->right!=NULL){
	    	
	       a[temp->right->data]=temp->data;
	    qe.push(temp->right);
	    
}
	    }
	   cout<<endl;
 for(int i=1;i<8;i++){
	cout<<a[i]<<"  ";
}
	

}

void path(node *ro){

	if(ro==NULL)
		return;
		qe.push(ro);
		while(!qe.empty()){
			// my testing
			node *temp= qe.front();
			qe.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
	    qe.push(temp->left); 

	    if(temp->right!=NULL)
	    qe.push(temp->right);
	    
	 
	    }
	   
 
	
	
}
	
	int main(){
		
root=newNode(1);
root->left=newNode(2);
root->right=newNode(3);
root->left->left=newNode(4);
root->left->right=newNode(5);
root->left->left->left=newNode(7);
root->right->left=newNode(6);
int n=8;
int a[8];
a[1]=-1;
labelorder(root,a);
cout<<endl;
int val=7,k=2;
int cnt=0;
//cout<<"gfd123";

//cout<<"gfd";
 while(val!=-1){
 	val=a[val];
 	if(++cnt==k)
 	break;
 }
 
	cout<<val;


	}