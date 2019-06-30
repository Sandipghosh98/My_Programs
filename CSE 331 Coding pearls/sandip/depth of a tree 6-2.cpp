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
		int t=0;
		void inorder(node *ro){
	if(ro==NULL)
		return;
		
		inorder(ro->left);
			cout<<ro->data<<" ";t++;
			qe.push(ro);
		inorder(ro->right);
	
}
	
	int main(){
		root=newNode(10);
		root->left=newNode(20);
root->right=newNode(30);
root->left->left=newNode(40);
root->left->right=newNode(50);
root->right->left=newNode(60);
root->right->left->right=newNode(70);
inorder(root);
int l=0,r=0;
int x=0;
while (!qe.empty()) 
    { 
       // cout << '\t' << qe.front();
		p=qe.front();
		x=p->data; 
        qe.pop();
        if(root->data==x){
        	break;
        }
		l++; 
    } 
   // cout<<endl<<"df";
	cout<<endl;
cout<<t<<"  "<<l<<" "<<(t-l);
	}
