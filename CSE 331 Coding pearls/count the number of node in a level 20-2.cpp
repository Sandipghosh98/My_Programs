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
int count=0;
	if(ro==NULL)
		return;
		qe.push(ro);
		qe.push(NULL);
		while(!qe.empty())
		{
			// my testing
			node *temp= qe.front();
			qe.pop(); 
		//	cout<<"ds"<<"  ";
			if(temp==NULL){
		//			cout<<"dsdadad"<<"  ";
				cout<<"number of nodes  "<<count;
				cout<<endl;
				qe.push(NULL);
				count=0;
			}
			
			
		//			cout<<"sabdds"<<"  ";
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
	    qe.push(temp->left); 

	    if(temp->right!=NULL)
	    qe.push(temp->right);
	    
	 
	    }	
}


int main(){
root=newNode(10);
root->left=newNode(20);
root->right=newNode(30);
root->left->left=newNode(40);
root->left->right=newNode(50);
labelorder(root);

}
