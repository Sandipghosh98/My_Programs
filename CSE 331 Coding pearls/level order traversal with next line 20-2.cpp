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
	queue <node *> qe;
void labelorder(node *ro){

	if(ro==NULL)
		return;
		qe.push(ro);
		qe.push(NULL);
		while(!qe.empty())
		{
			// my testing
			node *temp= qe.front();
			qe.pop();
			if(temp==NULL){
				cout<<endl;
				qe.push(NULL);
			}
			else
			{
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
	    qe.push(temp->left); 

	    if(temp->right!=NULL)
	    qe.push(temp->right);
	    }
	 
	    }	
}


int main(){

root=newNode(1);
root->left=newNode(2);
root->right=newNode(3);
root->left->left=newNode(4);
root->left->right=newNode(5);
root->right->left=newNode(6);

labelorder(root);
}
