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
void printLevel(node *root)
{
	if(!root)
	return;
	queue<node *>q;
	q.push(root);
	q.push(NULL);
	while(q.size()!=1)
	{
		node *temp=q.front();
		q.pop();
		if(temp)
		{
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
		else
		{
			cout<<endl;
			q.push(NULL);
		}
	}
}
node* newNode(int info)
{
     node* p =new node;
     p->info = info;
     p->left = NULL;
     p->right = NULL;
     return p;
}
int main()
{
	int data,n,k;
	bool flag=true;
	 struct node *root=newNode(1);
	 queue<node *>q;
	 q.push(root);
	 cin>>n;
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
	 printLevel(root);
}
