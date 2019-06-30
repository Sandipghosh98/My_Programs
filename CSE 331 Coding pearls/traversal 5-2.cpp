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
	
	void inorder(node *ro){
	if(ro==NULL)
		return;
		
	
		inorder(ro->left);
			cout<<ro->data<<" ";
		inorder(ro->right);
	
}
	void preorder(node *ro){
	if(ro==NULL)
		return;
			cout<<ro->data<<" ";
		preorder(ro->left);
		preorder(ro->right);
	
}

	void postorder(node *ro){
	if(ro==NULL)
		return;
		
		postorder(ro->left);
		postorder(ro->right);
		cout<<ro->data<<" ";
}

void labelorder(node *ro){
	queue <node *> qe;
	if(ro==NULL)
		return;
		qe.push(ro);
		while(!qe.empty()){
			// my testing
			node *temp= qe.front();
			qe.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
	    qe.push(temp->left); 

	    if(temp->right!=NULL)
	    qe.push(temp->right);
	    
	 
	    }
	   
 
	
	
}

void printLevelOrder(node *root)  
{  												// level order line by line
    // Base Case  
    if (root == NULL) return;  
  
    // Create an empty queue for level order tarversal  
    queue<node *> q;  
  
    // Enqueue Root and initialize height  
    q.push(root);  
  
    while (q.empty() == false)  
    {  
        // nodeCount (queue size) indicates number 
        // of nodes at current lelvel.  
        int nodeCount = q.size();  
  
        // Dequeue all nodes of current level and  
        // Enqueue all nodes of next level  
        while (nodeCount > 0) 
        {  
            node *node = q.front();  
            cout << node->data << " ";  
            q.pop();  
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            nodeCount--;  
        }  
        cout << endl;  
    }  
}


/*
// Function to insert nodes in level order 
Node* insertLevelOrder(int arr[], Node* root, 
                       int i, int n) 
{ 
    // Base case for recursion 
    if (i < n) 
    { 
        Node* temp = newNode(arr[i]); 
        root = temp; 
  
        // insert left child 
        root->left = insertLevelOrder(arr, 
                   root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insertLevelOrder(arr, 
                  root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
  
*/





int main(){

root=newNode(10);
root->left=newNode(20);
root->right=newNode(30);
root->left->left=newNode(40);
root->left->right=newNode(50);
inorder(root);
cout<<endl;
preorder(root);
cout<<endl;
postorder(root);
cout<<endl;
labelorder(root);
/*
while (!qe.empty()) 
    { 
        cout << '\t' << qe.front(); 
        qe.pop(); 
    } 
//label order traversal
*/
}
