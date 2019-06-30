#include<bits/stdc++.h>
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
/*	void in(int d,int ro){
		new *node;
		if(ro==NULL){
			
		}
	}
	
	
*/	
void insertion(node *root,int data){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node *curr=q.front();
		q.pop();
		if(curr->left==NULL){
			curr->left=newNode(data);
			break;
		}
		else
		q.push(curr->left);
		if(curr->right == NULL){
			curr->right=newNode(data);
			break;
		}
		else
		q.push(curr->right);

	}
}
void inorder(node *ro){
	if(ro==NULL)
		return;
		inorder(ro->left);
		cout<<ro->data<<" ";
		inorder(ro->right);
	
}	
	
	
	
	
	
	int  main(){
	cout<<"sandip"<<endl;
	
root=newNode(10);
root->left=newNode(20);
root->right=newNode(30);
root->left->left=newNode(40);
root->left->right=newNode(50);
cout<<"sandip"<<endl;
inorder(root);
node *root=newNode(10);
insertion(root,25);
/*
	while(1){
		cout<<"1. for insertion in binary tree"<<endl;
			cout<<"2. for deletion in binary tree"<<endl;
				cout<<"3. for traversal in binary tree"<<endl;
					cout<<"4. for finding an element in binary tree"<<endl;
						cout<<"5. for exit"<<endl;
							cout<<"enter your choice"<<endl;
							int ch;
							switch(ch){
								default:
									cout<<"wrong choice"<<endl;
								break;
								case 1:
									int d;
									cout<<enter the number u want to insert"<<endl;
									cin>>d;
									in(d,ro);
									break;
								case 2:
									
									
									cout<<"the number is deleted"<<endl;
									break;
								case 3:
									traversal();
									break;
								case 4:
									cout<<"enter the element u want to search"<<endl;
									int f;
									cout>>f;
									break;
								case 5:
									system.exit(0);
							}
							
							
							
	*/
	return 0;
}
