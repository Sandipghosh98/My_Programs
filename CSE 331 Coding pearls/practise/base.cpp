vector<int> g;
g1.push_back(3);
g1.pop_back(4)// delete from the last
g1.front();
g1.back();
sort(g1.begin(),g1.end(),greater<int>())

vector<pair<int,int> > v;
v.push_back(make_pair(1,2))
v.first;v[i].second;
sort(g1.begin(),g1.end()) //with the first number
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
 sort(vect.begin(), vect.end(), sortbysec);
//insert level wise
  Node* root = insertLevelOrder(arr, root, 0, n);
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

//*******************************************************
dele(root,70);
deletion in binary tree

	void dele(node *ro,int t){

	if(ro==NULL)
		return;
		qe.push(ro);
			//node *v,*b;
			int v;
		while(!qe.empty()){
			// my testing
		
			node *temp= qe.front();
			qe.pop();
			if(temp->data==t){
			//	cout<<"de"<<endl;
			//	int v=temp->data;
			q=temp;
			v=temp->data;
			}
			cout<<temp->data<<" ";
			y=temp->data;
			p=temp;
		//	node *b=temp;
			if(temp->left!=NULL)
	    qe.push(temp->left); 

	    if(temp->right!=NULL)
	    qe.push(temp->right);
	    
	 
	    }
	  //  cout<<endl<<"fg"<<endl;
	    //cout<<v->data<<"  "<<y<<"  "<<b->data;
	    cout<<endl<<v<<endl;
	    cout<<y<<endl;
	    q->data=y;
	    cout<<q<<endl;
	    cout<<p<<endl;
	    
	}


//*********************************************************

traversal  

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

//*************************************************************
  
node* root=newNode(arr[0]);
//	node* root1=makeBST(arr,1,n-1,root);
	for(int i=1;i<n;i++){
	val=arr[i];
		makeBST(root,val); }

insertion in BST

node* makeBST(node *ro,int v){
//	node* temp=ro;
	if(ro==NULL)
	ro=newNode(v);
	else if(ro->data<v)
	ro->right=makeBST(ro->right,v);
	else
	ro->left=makeBST(ro->left,v);
	
	return ro;
	}


//***********************************************

deletion in BST
del(root,d);
node* findminright(node *root){
	while(root->left!=NULL)
		root=root->left;
	return root;
}

	node* del(node *root,int data){
		//cout<<l<<endl;
	if(root==NULL)
		return root;
	else if(data<root->data)
	root->left=del(root->left, data);
		else if(data>root->data)
	root->right=del(root->right, data);
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root=NULL;
		}
		else if(root->left==NULL){
			node *temp=root;
			root=root->left;
			delete temp;
		}
		else{
			node *temp=findminright(root->right);
			root->data =temp->data;
			root->right=del(root->right,temp->data);
		}
	}
	return root;
}


//******************************************************************

#include <stdio.h> 
#include <stdlib.h> 
  
struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 
  
/* Function to find LCA of n1 and n2. The function assumes that both 
   n1 and n2 are present in BST */
struct node *lca(struct node* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
  
    // If both n1 and n2 are smaller than root, then LCA lies in left 
    if (root->data > n1 && root->data > n2) 
        return lca(root->left, n1, n2); 
  
    // If both n1 and n2 are greater than root, then LCA lies in right 
    if (root->data < n1 && root->data < n2) 
        return lca(root->right, n1, n2); 
  
    return root; 
} 
  
/* Helper function that allocates a new node with the given data.*/
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data  = data; 
    node->left  = node->right = NULL; 
    return(node); 
} 
  
/* Driver program to test lca() */
int main() 
{ 
    // Let us construct the BST shown in the above figure 
    struct node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 
  
    int n1 = 10, n2 = 14; 
    struct node *t = lca(root, n1, n2); 
    printf("LCA of %d and %d is %d \n", n1, n2, t->data); 
  
    n1 = 14, n2 = 8; 
    t = lca(root, n1, n2); 
    printf("LCA of %d and %d is %d \n", n1, n2, t->data); 
  
    n1 = 10, n2 = 22; 
    t = lca(root, n1, n2); 
    printf("LCA of %d and %d is %d \n", n1, n2, t->data); 
  
    getchar(); 
    return 0; 
}

//*********************************************************

pre and post sucessor

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



