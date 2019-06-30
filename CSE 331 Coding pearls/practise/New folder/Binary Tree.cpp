#include<bits/stdc++.h>
using namespace std;
struct node
{
	int info;
	node *left;
	node *right;
};
node *x;
int c=0;
node* newNode(int info)
{
     node* p =new node;
     p->info = info;
     p->left = NULL;
     p->right = NULL;
     return p;
}
void findk(node* node,int k)
{
	if(node==NULL)
	return;
	if(c<=k)
	{
		c++;
		if(c==k)
		cout<<node->info<<endl;
		findk(node->left,k);
		findk(node->right,k);
	}
}
int height(node *root)
{
	if(root==NULL)
	return 0;
	return 1 + max(height(root->left),height(root->right));
}
void deletion(node *root,int data)
{
	int i=0;
   queue<node*> q;
   q.push(root);
   node *temp, *temp1, *temp2;
   while(!q.empty())
   {
       temp=q.front();
       q.pop();
       temp2=temp;
       if(temp->info==data)
       {
       		temp1=temp;
       }
       if(temp->left)
       {
           q.push(temp->left);
       }
       if(temp->right)
       {
           q.push(temp->right);
       }
   }
   swap(temp1->info,temp2->info);
   q.push(root);
   while(!q.empty())
   {
       temp=q.front();
       q.pop();
       if(temp->left)
       {
       		if(temp->left==temp2)
       		{
       			temp->left=NULL;
       			break;
       		}
           q.push(temp->left);
       }
       if(temp->right)
       {
       		if(temp->right==temp2)
       		{
       			temp->right=NULL;
       			break;
       		}
           q.push(temp->right);
       }
   }
   delete temp2;
}
void level(node * root)
{
	int i=0;
   queue<node*> q;
   q.push(root);
   node *temp;
   while(!q.empty())
   {
       temp=q.front();
       q.pop();
       cout<<temp->info<<" ";
       if(temp->left)
       {
           q.push(temp->left);
       }
       if(temp->right)
       {
           q.push(temp->right);
       }
   }
   cout<<endl;
}
void preorder(node* node)
{
	if(node==NULL)
	return;
	cout<<node->info<<" ";
	preorder(node->left);
	preorder(node->right);
}
void postorder(node* node)
{
	if(node==NULL)
	return;
	postorder(node->left);
	postorder(node->right);
	cout<<node->info<<" ";	
}
void inorder(node* node)
{
	if(node==NULL)
	return;
	inorder(node->left);
	cout<<node->info<<" ";
	inorder(node->right);
}
int main()
{
	int data,n,k;
	bool flag=true;
	 struct node *root=newNode(1);
     //Without Queue ->
	 /*root->left=newNode(2);
     root->right=newNode(3);
     root->left->left=newNode(4);
     root->left->right=newNode(5);*/
	 queue<node *>q;
	 q.push(root);
	 cin>>n;
	 //With Queue ->
	 while(n--)
	 {
	 	flag=true;
	 	cin>>data;
	 	node *n1=q.front();
	 	while(flag)
	 	{
	 		n1=q.front();
	 		if(!n1->left)
	 		{
	 			n1->left=newNode(data);
	 			q.push(n1->left);
	 			flag=false;
	 		}
	 		else if(!n1->right)
	 		{
			 	n1->right=newNode(data);
			 	q.push(n1->right);
	 			flag=false;
	 		}
	 		else if(n1->left && n1->right)
	 		{
	 			q.pop();
	 		}
	 	}
	 }
     cout<<"Pre Order:"<<endl;
     preorder(root);
     cout<<endl<<"Post Order:"<<endl;
     postorder(root);
     cout<<endl<<"In Order:"<<endl;
     inorder(root);
     cout<<endl<<"Level Order: "<<endl;
     level(root);
     cout<<"Enter Value to Delete: ";
     cin>>data;
     cout<<endl;
     deletion(root,data);
     level(root);
     cout<<"Height: "<<height(root)<<endl;
     cout<<"Enter k : ";
     cin>>k;
     cout<<endl;
     findk(root,k);
}
