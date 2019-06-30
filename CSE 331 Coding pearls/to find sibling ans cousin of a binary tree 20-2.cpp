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
	queue <int> level;
	queue <int> par;
	
void labelorder(node *ro){

	if(ro==NULL)
		return;
		qe.push(ro);
		while(!qe.empty()){
		
			node *temp= qe.front();
			
			
			qe.pop();
			level.push(temp->data);
			//cout<<temp->data<<" ";
			if(temp->left!=NULL){
				    qe.push(temp->left); 
				 	par.push(temp->data);   
				}

	    if(temp->right!=NULL)
	   // cout<<temp->data<<"  ";
	    qe.push(temp->right);
	    par.push(temp->data);
	 
	    }
	   
 
	
	
}
void check(node *root,int x,int y){
	queue<node*> q;
	int xlvl=0,ylvl=0,lvl=0,xparent=0,yparent=0;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		q.pop();
			node *curr= qe.front();
		if(curr ==NULL){
			lvl++;
			q.push(NULL);
		}
		else{
			if(curr->left){
				if(curr->left->data==x){
					xlvl=lvl;
					xparent=curr->data;
				}
				if(curr->left->data==y){
					ylvl=lvl;
					yparent=curr->data;
				}
				q.push(curr->left);
			}
			else{
				if(curr->right){
				if(curr->right->data==x){
					xlvl=lvl;
					xparent=curr->data;
				}
				if(curr->right->data==y){
					ylvl=lvl;
					yparent=curr->data;
				}
				q.push(curr->right);
			}
				
			}
		}
		
	}
	if(xlvl==ylvl && xparent!=yparent){
		cout<<"cousin"<<endl;
		
	}else{
			cout<<"not cousin"<<endl;
	}
}
	

int main(){

root=newNode(1);
root->left=newNode(2);
root->right=newNode(3);
root->left->left=newNode(4);
root->left->right=newNode(5);
root->right->left=newNode(6);
root->left->left->left=newNode(7);
//labelorder(root);
check(root,4,5);
cout<<endl;
/*	while(!level.empty()){
		cout<<level.front()<<" ";
		level.pop();
		
		
	}
	cout<<endl;
	for(int i=0;i<6;i++){
	
		cout<<par.front()<<" ";
		par.pop();
		
		
	}
	*/
}
