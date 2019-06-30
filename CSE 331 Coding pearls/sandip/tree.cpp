//normal binary tree insertion

// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
   
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    // print inoder traversal of the BST 
    inorder(root); 
   
    return 0; 
}


********************************************************************************
//all traversal 


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

********************************************************************************

k th ancester of a node

/* C++ program to calculate Kth ancestor of given node */
#include <iostream> 
#include <queue> 
using namespace std; 

// A Binary Tree Node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// temporary node to keep track of Node returned 
// from previous recursive call during backtrack 
Node* temp = NULL; 

// recursive function to calculate Kth ancestor 
Node* kthAncestorDFS(Node *root, int node , int &k) 
{ 
	// Base case 
	if (!root) 
		return NULL; 
	
	if (root->data == node|| 
	(temp = kthAncestorDFS(root->left,node,k)) || 
	(temp = kthAncestorDFS(root->right,node,k))) 
	{ 
		if (k > 0)		 
			k--; 
		
		else if (k == 0) 
		{ 
			// print the kth ancestor 
			cout<<"Kth ancestor is: "<<root->data; 
			
			// return NULL to stop further backtracking 
			return NULL; 
		} 
		
		// return current node to previous call 
		return root; 
	} 
} 

// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	// Let us create binary tree shown in above diagram 
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	int k = 2; 
	int node = 5; 

	// print kth ancestor of given node 
	Node* parent = kthAncestorDFS(root,node,k); 
	
	// check if parent is not NULL, it means 
	// there is no Kth ancestor of the node 
	if (parent) 
		cout << "-1"; 
	
	return 0; 
} 

***************************************************
skewed tree
// C++ program to Check whether a given 
// binary tree is skewed binary tree or not? 

#include <bits/stdc++.h> 
using namespace std; 

// A Tree node 
struct Node { 
	int key; 
	struct Node *left, *right; 
}; 

// Utility function to create a new node 
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 

bool isSkewedBT(Node* root) 
{ 
	// check if node is NULL or is a leaf node 
	if (root == NULL || (root->left == NULL && 
						root->right == NULL)) 
		return true; 

	// check if node has two children if 
	// yes, return false 
	if (root->left && root->right) 
		return false; 
	if (root->left) 
		return isSkewedBT(root->left); 
	return isSkewedBT(root->right); 
} 

// Driver program 
int main() 
{ 
	/* 10 
	/	 \ 
	12	 13 
		/	 \ 
		14	 15	 
		/ \	 / \ 
	21 22 23 24		 
	Let us create Binary Tree shown in above example */
	Node* root = newNode(10); 
	root->left = newNode(12); 
	root->left->right = newNode(15); 
	cout << isSkewedBT(root) << endl; 

	root = newNode(5); 
	root->right = newNode(4); 
	root->right->left = newNode(3); 
	root->right->left->right = newNode(2); 
	cout << isSkewedBT(root) << endl; 

	root = newNode(5); 
	root->left = newNode(4); 
	root->left->right = newNode(3); 
	root->left->right->left = newNode(2); 
	root->left->right->right = newNode(4); 
	cout << isSkewedBT(root) << endl; 
} 

**************************************************

finding sibling

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

void checkCousin(node *root,int x,int y)
{
    queue<node*>q;
    int x1v1=0,y1v1=0,lvl=0,xparent=0,yparent=0;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {

        node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            lvl++;
            q.push(NULL);
        }
        else{
            if(curr->left)
            {

                if(curr->left->data==x)
                {

                    x1v1=lvl;
                    xparent=curr->data;

                }
                if(curr->left->data==y)
                {

                    y1v1=lvl;
                    yparent=curr->data;
                }
                q.push(curr->left);
            }

            if(curr->right)
            {

                if(curr->left->data==x)
                {

                    x1v1=lvl;
                    xparent=curr->data;

                }
                if(curr->left->data==y)
                {

                    y1v1=lvl;
                    yparent=curr->data;
                }
                q.push(curr->right);
            }
        }
    }
    if(x1v1=y1v1 && xparent!=yparent)
    {

        cout<<"COUSIN"<<endl;
    }
    else{
        cout<<"NON COUSIN"<<endl;
    }

}


int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->left->left->left=newNode(7);
    checkCousin(root,4,3);

    return 0;
}

*************************************************************
lowest common ansestor 

// CPP code to find LCA of given 
// two nodes in a tree 
#include <algorithm> 
#include <iostream> 
#include <vector> 

#define sz(x) x.size() 
#define pb push_back 
#define left 2 * i + 1 
#define right 2 * i + 2 
using namespace std; 

const int maxn = 100005; 

// the graph 
vector<vector<int>> g(maxn); 

// level of each node 
int level[maxn]; 

vector<int> e; 
vector<int> l; 
int h[maxn]; 

// the segment tree 
int st[5 * maxn]; 

// adding edges to the graph(tree) 
void add_edge(int u, int v) { 
g[u].pb(v); 
g[v].pb(u); 
} 

// assigning level to nodes 
void leveling(int src) { 
for (int i = 0; i < sz(g[src]); i++) { 
	int des = g[src][i]; 
	if (!level[des]) { 
	level[des] = level[src] + 1; 
	leveling(des); 
	} 
} 
} 

bool visited[maxn]; 

// storing the dfs traversal 
// in the array e 
void dfs(int src) { 
e.pb(src); 
visited[src] = 1; 
for (int i = 0; i < sz(g[src]); i++) { 
	int des = g[src][i]; 
	if (!visited[des]) { 
	dfs(des); 
	e.pb(src); 
	} 
} 
} 

// making the array l 
void setting_l(int n) { 
for (int i = 0; i < sz(e); i++) 
	l.pb(level[e[i]]); 
} 

// making the array h 
void setting_h(int n) { 
for (int i = 0; i <= n; i++) 
	h[i] = -1; 
for (int i = 0; i < sz(e); i++) { 
	// if is already stored 
	if (h[e[i]] == -1) 
	h[e[i]] = i; 
} 
} 

// Range minimum query to return the index 
// of minimum in the subarray L[qs:qe] 
int RMQ(int ss, int se, int qs, int qe, int i) { 
if (ss > se) 
	return -1; 

// out of range 
if (se < qs || qe < ss) 
	return -1; 

// in the range 
if (qs <= ss && se <= qe) 
	return st[i]; 

int mid = (ss + se) >> 1; 
int st = RMQ(ss, mid, qs, qe, left); 
int en = RMQ(mid + 1, se, qs, qe, right); 

if (st != -1 && en != -1) { 
	if (l[st] < l[en]) 
	return st; 
	return en; 
} else if (st != -1) 
	return st; 
else if (en != -1) 
	return en; 
} 

// constructs the segment tree 
void SegmentTreeConstruction(int ss, int se, int i) { 
if (ss > se) 
	return; 
if (ss == se) // leaf 
{ 
	st[i] = ss; 
	return; 
} 
int mid = (ss + se) >> 1; 

SegmentTreeConstruction(ss, mid, left); 
SegmentTreeConstruction(mid + 1, se, right); 

if (l[st[left]] < l[st[right]]) 
	st[i] = st[left]; 
else
	st[i] = st[right]; 
} 

// Funtion to get LCA 
int LCA(int x, int y) { 
if (h[x] > h[y]) 
	swap(x, y); 
return e[RMQ(0, sz(l) - 1, h[x], h[y], 0)]; 
} 

// Driver code 
int main() { 
ios::sync_with_stdio(0); 

// n=number of nodes in the tree 
// q=number of queries to answer 
int n = 15, q = 5; 

// making the tree 
/* 
				1 
				/ | \ 
				2 3 4 
				| \ 
				5 6 
				/ | \ 
			8 7 9 (right of 5) 
				/ | \ | \ 
			10 11 12 13 14 
					| 
					15 
*/
add_edge(1, 2); 
add_edge(1, 3); 
add_edge(1, 4); 
add_edge(3, 5); 
add_edge(4, 6); 
add_edge(5, 7); 
add_edge(5, 8); 
add_edge(5, 9); 
add_edge(7, 10); 
add_edge(7, 11); 
add_edge(7, 12); 
add_edge(9, 13); 
add_edge(9, 14); 
add_edge(12, 15); 

level[1] = 1; 
leveling(1); 

dfs(1); 

setting_l(n); 

setting_h(n); 

SegmentTreeConstruction(0, sz(l) - 1, 0); 

cout << LCA(10, 15) << endl; 
cout << LCA(11, 14) << endl; 

return 0; 
} 

***************************************************************
inorder suceesor of all node

#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
	struct node* parent; 
}; 

struct node * minValue(struct node* node); 

struct node * inOrderSuccessor(struct node *root, struct node *n) 
{ 
// step 1 of the above algorithm 
if( n->right != NULL ) 
	return minValue(n->right); 

// step 2 of the above algorithm 
struct node *p = n->parent; 
while(p != NULL && n == p->right) 
{ 
	n = p; 
	p = p->parent; 
} 
return p; 
} 

/* Given a non-empty binary search tree, return the minimum data 
	value found in that tree. Note that the entire tree does not need 
	to be searched. */
struct node * minValue(struct node* node) { 
struct node* current = node; 

/* loop down to find the leftmost leaf */
while (current->left != NULL) { 
	current = current->left; 
} 
return current; 
} 

/* Helper function that allocates a new node with the given data and 
	NULL left and right pointers. */
struct node* newNode(int data) 
{ 
struct node* node = (struct node*) 
					malloc(sizeof(struct node)); 
node->data = data; 
node->left = NULL; 
node->right = NULL; 
node->parent = NULL; 
	
return(node); 
} 

/* Give a binary search tree and a number, inserts a new node with	 
	the given number in the correct place in the tree. Returns the new 
	root pointer which the caller should then use (the standard trick to 
	avoid using reference parameters). */
struct node* insert(struct node* node, int data) 
{ 
/* 1. If the tree is empty, return a new, 
	single node */
if (node == NULL) 
	return(newNode(data)); 
else
{ 
	struct node *temp; 

	/* 2. Otherwise, recur down the tree */
	if (data <= node->data) 
	{	 
		temp = insert(node->left, data); 
		node->left = temp; 
		temp->parent= node; 
	} 
	else
	{ 
		temp = insert(node->right, data); 
		node->right = temp; 
		temp->parent = node; 
	}	 

	/* return the (unchanged) node pointer */
	return node; 
} 
} 

/* Driver program to test above functions*/
int main() 
{ 
struct node* root = NULL, *temp, *succ, *min; 

//creating the tree given in the above diagram 
root = insert(root, 20); 
root = insert(root, 8); 
root = insert(root, 22); 
root = insert(root, 4); 
root = insert(root, 12); 
root = insert(root, 10); 
root = insert(root, 14);	 
temp = root->left->right->right; 

succ = inOrderSuccessor(root, temp); 
if(succ != NULL) 
	printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);	 
else
	printf("\n Inorder Successor doesn't exit"); 

getchar(); 
return 0; 
} 

****************************************************************

to make post traversal using pre and in order

    // C++ program to print postorder traversal from preorder and inorder traversals 
#include <iostream> 
using namespace std; 
  
// A utility function to search x in arr[] of size n 
int search(int arr[], int x, int n) 
{ 
    for (int i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
// Prints postorder traversal from given inorder and preorder traversals 
void printPostOrder(int in[], int pre[], int n) 
{ 
    // The first element in pre[] is always root, search it 
    // in in[] to find left and right subtrees 
    int root = search(in, pre[0], n); 
  
    // If left subtree is not empty, print left subtree 
    if (root != 0) 
        printPostOrder(in, pre + 1, root); 
  
    // If right subtree is not empty, print right subtree 
    if (root != n - 1) 
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1); 
  
    // Print root 
    cout << pre[0] << " "; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int in[] = { 4, 2, 5, 1, 3, 6 }; 
    int pre[] = { 1, 2, 4, 5, 3, 6 }; 
    int n = sizeof(in) / sizeof(in[0]); 
    cout << "Postorder traversal " << endl; 
    printPostOrder(in, pre, n); 
    return 0; 
}
    
***************************************************************************************

Predecessor and succesor of a node




#include<bits/stdc++.h>
using namespace std; 
  
// BST Node 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// This function finds predecessor and successor of key in BST. 
// It sets pre and suc as predecessor and successor respectively 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    // Base case 
    if (root == NULL)  return ; 
  
    // If key is present at root 
    if (root->key == key) 
    { 
        // the maximum value in left subtree is predecessor 
        if (root->left != NULL) 
        { 
            Node* tmp = root->left; 
            while (tmp->right) 
                tmp = tmp->right; 
            pre = tmp ; 
        } 
  
        // the minimum value in right subtree is successor 
        if (root->right != NULL) 
        { 
            Node* tmp = root->right ; 
            while (tmp->left) 
                tmp = tmp->left ; 
            suc = tmp ; 
        } 
        return ; 
    } 
  
    // If key is smaller than root's key, go to left subtree 
    if (root->key > key) 
    { 
        suc = root ; 
        findPreSuc(root->left, pre, suc, key) ; 
    } 
    else // go to right subtree 
    { 
        pre = root ; 
        findPreSuc(root->right, pre, suc, key) ; 
    } 
} 
  
// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
    Node *temp =  new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
    return node; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int key = 65;    //Key to be searched in BST 
  
   /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
  
  
    Node* pre = NULL, *suc = NULL; 
  
    findPreSuc(root, pre, suc, key); 
    if (pre != NULL) 
      cout << "Predecessor is " << pre->key << endl; 
    else
      cout << "No Predecessor"; 
  
    if (suc != NULL) 
      cout << "Successor is " << suc->key; 
    else
      cout << "No Successor"; 
    return 0; 
}

**************************************************************************************

delection of tree node

// C program to demonstrate delete operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d ", root->key); 
		inorder(root->right); 
	} 
} 

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

/* Given a non-empty binary search tree, return the node with minimum 
key value found in that tree. Note that the entire tree does not 
need to be searched. */
struct node * minValueNode(struct node* node) 
{ 
	struct node* current = node; 

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL) 
		current = current->left; 

	return current; 
} 

/* Given a binary search tree and a key, this function deletes the key 
and returns the new root */
struct node* deleteNode(struct node* root, int key) 
{ 
	// base case 
	if (root == NULL) return root; 

	// If the key to be deleted is smaller than the root's key, 
	// then it lies in left subtree 
	if (key < root->key) 
		root->left = deleteNode(root->left, key); 

	// If the key to be deleted is greater than the root's key, 
	// then it lies in right subtree 
	else if (key > root->key) 
		root->right = deleteNode(root->right, key); 

	// if key is same as root's key, then This is the node 
	// to be deleted 
	else
	{ 
		// node with only one child or no child 
		if (root->left == NULL) 
		{ 
			struct node *temp = root->right; 
			free(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			struct node *temp = root->left; 
			free(root); 
			return temp; 
		} 

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		struct node* temp = minValueNode(root->right); 

		// Copy the inorder successor's content to this node 
		root->key = temp->key; 

		// Delete the inorder successor 
		root->right = deleteNode(root->right, temp->key); 
	} 
	return root; 
} 

// Driver Program to test above functions 
int main() 
{ 
	/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	struct node *root = NULL; 
	root = insert(root, 50); 
	root = insert(root, 30); 
	root = insert(root, 20); 
	root = insert(root, 40); 
	root = insert(root, 70); 
	root = insert(root, 60); 
	root = insert(root, 80); 

	printf("Inorder traversal of the given tree \n"); 
	inorder(root); 

	printf("\nDelete 20\n"); 
	root = deleteNode(root, 20); 
	printf("Inorder traversal of the modified tree \n"); 
	inorder(root); 

	printf("\nDelete 30\n"); 
	root = deleteNode(root, 30); 
	printf("Inorder traversal of the modified tree \n"); 
	inorder(root); 

	printf("\nDelete 50\n"); 
	root = deleteNode(root, 50); 
	printf("Inorder traversal of the modified tree \n"); 
	inorder(root); 

	return 0; 
} 

