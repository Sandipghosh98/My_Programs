
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
struct Node
{
    int data;
    Node* left, * right;
};

/* Helper function that allocates a
new node */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

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

// Function to print tree nodes in
// InOrder fashion
void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}

  void labelorder(Node *ro){
	queue <Node *> qe;
	if(ro==NULL)
		return;
		qe.push(ro);
		while(!qe.empty()){
			// my testing
			Node *temp= qe.front();
			qe.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
	    qe.push(temp->left);

	    if(temp->right!=NULL)
	    qe.push(temp->right);
	    }}
// Driver program to test above function
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = insertLevelOrder(arr, root, 0, n);
    inOrder(root);
    cout<<endl;
    labelorder(root);

}
