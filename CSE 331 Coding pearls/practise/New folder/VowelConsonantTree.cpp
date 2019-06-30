#include<bits/stdc++.h>
using namespace std;
struct node
{
	char info;
	node *left;
	node *right;
};
node* newNode(char info)
{
     node* p =new node;
     p->info = info;
     p->left = NULL;
     p->right = NULL;
     return p;
}
node *createTree(string s)
{
	int i,n=s.length();
	queue<node *> q;
	node *n1,*a;
	bool flag=true,flag1=true;
	for(i=0;i<n;i++)
	{
		if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
		{
			if(flag)
			{
				*a=newNode(s[i]);
				q.push(a);
				flag=false;
			}
			else
			{
				while(flag1)
	 			{
	 				n1=q.front();
	 				if(!n1->left)
	 				{
	 					n1->left=newNode(s[i]);
	 					q.push(n1->left);
	 					flag1=false;
	 				}
	 				else if(!n1->right)
	 				{
			 			n1->right=newNode(s[i]);
			 			q.push(n1->right);
	 					flag1=false;
	 				}
	 				else if(n1->left && n1->right)
	 				{
	 					q.pop();
	 				}
	 			}
			}
		}
	}
	return a;
}
node *createTree1(string s)
{
	int i,n=s.length();
	queue<node *> q;
	node *n1,*b;
	bool flag=true,flag1=true;
	for(i=0;i<n;i++)
	{
		if(s[i]=='a' && s[i]=='e' && s[i]=='i' && s[i]=='o' && s[i]=='u')
		{
			if(flag)
			{
				*b=newNode(s[i]);
				q.push(b);
				flag=false;
			}
			else
			{
				while(flag1)
	 			{
	 				n1=q.front();
	 				if(!n1->left)
	 				{
	 					n1->left=newNode(s[i]);
	 					q.push(n1->left);
	 					flag1=false;
	 				}
	 				else if(!n1->right)
	 				{
			 			n1->right=newNode(s[i]);
			 			q.push(n1->right);
	 					flag1=false;
	 				}
	 				else if(n1->left && n1->right)
	 				{
	 					q.pop();
	 				}
	 			}
			}
		}
	}
	return b;
}
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
int main()
{
	int data,n,k;
	bool flag=true;
	 struct node *root=newNode('?');
	 string s;
	 cin>>s;
	 node *a=createTree(s);
	 node *b=createTree1(s);
	 root->left=a;
	 root->right=b;
	 printLevel(root);
}
