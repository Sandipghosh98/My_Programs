#include<bits/stdc++.h>
#include <queue> 
//deletion in a tree
using namespace std;
	struct node{
		int data;
		node *left, *right;
		
	}*root=NULL,*p,*q;
	node *newNode(int data){
		node* newnode= new node;
		newnode->data=data;
		newnode->left=newnode->right=NULL;
		return newnode;
	}
	int y=0;
		queue <node *> qe;
			void la(node *ro){

	if(ro==NULL)
		return;
		qe.push(ro);
			//node *v,*b;
			int v;
		while(!qe.empty()){
			// my testing
		
			node *temp= qe.front();
			qe.pop();
		/*	if(temp->data==t){
			//	cout<<"de"<<endl;
			//	int v=temp->data;
			q=temp;
			v=temp->data;
			}
			*/
			if(p==temp){
				delete temp;
				return;
			}
			cout<<temp->data<<" ";
		//	y=temp->data;
		//	p=temp;
		//	node *b=temp;
			if(temp->left!=NULL)
	    qe.push(temp->left); 

	    if(temp->right!=NULL)
	    qe.push(temp->right);
	    
	 
	    }
	    /*
	    cout<<endl<<"fg"<<endl;
	    //cout<<v->data<<"  "<<y<<"  "<<b->data;
	    cout<<v<<endl;
	    cout<<y<<endl;
	    q->data=70;
	    cout<<q<<endl;
	    cout<<p<<endl;
	    */
	    
	}
		/*
		
		void lab(node *ro){

	if(ro==NULL)
		return;
		qe.push(ro);
			//node *v,*b;
			int v;
		while(!qe.empty()){
			// my testing
		
			node *temp= qe.front();
			qe.pop();
		/*	if(temp->data==t){
			//	cout<<"de"<<endl;
			//	int v=temp->data;
			q=temp;
			v=temp->data;
			}
			*/
			/*
			cout<<temp->data<<" ";
		//	y=temp->data;
		//	p=temp;
		//	node *b=temp;
			if(temp->left!=NULL)
	    qe.push(temp->left); 

	    if(temp->right!=NULL)
	    qe.push(temp->right);
	    
	 
	    }
	    /*
	    cout<<endl<<"fg"<<endl;
	    //cout<<v->data<<"  "<<y<<"  "<<b->data;
	    cout<<v<<endl;
	    cout<<y<<endl;
	    q->data=70;
	    cout<<q<<endl;
	    cout<<p<<endl;
	    */
	    
	//}
	
		
	void dele(node *ro,int t){

	if(ro==NULL)
		return;
		qe.push(ro);
			//node *v,*b;
			int v;
		while(!qe.empty()){
			// my testing
		
			node *temp= qe.front();
			qe.pop();
			if(temp->data==t){
			//	cout<<"de"<<endl;
			//	int v=temp->data;
			q=temp;
			v=temp->data;
			}
			cout<<temp->data<<" ";
			y=temp->data;
			p=temp;
		//	node *b=temp;
			if(temp->left!=NULL)
	    qe.push(temp->left); 

	    if(temp->right!=NULL)
	    qe.push(temp->right);
	    
	 
	    }
	  //  cout<<endl<<"fg"<<endl;
	    //cout<<v->data<<"  "<<y<<"  "<<b->data;
	    cout<<endl<<v<<endl;
	    cout<<y<<endl;
	    q->data=y;
	    cout<<q<<endl;
	    cout<<p<<endl;
	    
	}
	int main(){

root=newNode(10);
root->left=newNode(20);
root->right=newNode(30);
root->left->left=newNode(40);
root->left->right=newNode(50);
root->right->left=newNode(60);
root->right->left->right=newNode(70);
int r=30;
dele(root,30);
cout<<endl;
la(root);




}
