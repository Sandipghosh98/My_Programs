#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* left, *right;
};

node* newNode(int data)
{
    node* newnode = new node;
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
};
int p=1;
void levelorder(node *root)
{
    queue<node *>q;
    node* var=new node;
    var->data=-1;
    var->left=var->right=NULL;
    q.push(root);
    q.push(var);
    while(q.size()!=1 || q.front()->data!=-1 )
    {
        node *da=q.front();
        q.pop();
        if(da->data==-1)
        {  
        
            cout<<endl;
            
            q.push(var);
            continue;
        }
        cout<<da->data<<" ";
        if(da->left!=NULL)
        {
            q.push(da->left);
        }
        if(da->right!=NULL)
        {
            q.push(da->right);
        }

    }
}
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left=newNode(5);
    root->right->right=newNode(6);
    root->right->left->right=newNode(7);
    levelorder(root);

    return 0;
}
