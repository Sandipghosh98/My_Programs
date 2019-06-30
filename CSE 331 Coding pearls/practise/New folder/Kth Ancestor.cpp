#include<bits/stdc++.h>
using namespace std;
struct node
{
	int info;
	node *left;
	node *right;
};
node *x;
int a[10000];
int c=0;
node* newNode(int info)
{
     node* p =new node;
     p->info = info;
     p->left = NULL;
     p->right = NULL;
     return p;
}
int findAncestor(int k,int data)
{
	while(k--)
	{
		data=a[data];
	}
	return data;
}
void ancestor(node *root)
{
	if(root==NULL)
	return;
	queue<node *>q;
	q.push(root);
	a[root->info]=-1;
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		if(temp->left)
		{
			q.push(temp->left);
			a[temp->left->info]=temp->info;
		}
		if(temp->right)
		{
			q.push(temp->right);
			a[temp->right->info]=temp->info;
		}
	}
}
int main()
{
	int data,n,k;
	bool flag=true;
	struct node *root=newNode(1);
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
	 ancestor(root);
	 cout<<"Enter a value: ";
	 cin>>data;
	 cout<<endl<<"Enter Ancestor Value: ";
	 cin>>k;
	 cout<<findAncestor(k,data)<<endl;;
}
