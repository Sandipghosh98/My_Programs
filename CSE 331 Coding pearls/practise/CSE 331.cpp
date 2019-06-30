// CPP program to find distance between 
// two nodes in BST 
#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    struct Node* left, *right; 
    int key; 
}; 
  
struct Node* newNode(int key) 
{ 
    struct Node* ptr = new Node; 
    ptr->key = key; 
    ptr->left = ptr->right = NULL; 
    return ptr; 
} 
  
// Standard BST insert function 
struct Node* insert(struct Node* root, int key) 
{ 
    if (!root) 
        root = newNode(key); 
    else if (root->key > key) 
        root->left = insert(root->left, key); 
    else if (root->key < key) 
        root->right = insert(root->right, key); 
    return root; 
} 
  
// This function returns distance of x from 
// root. This function assumes that x exists 
// in BST and BST is not NULL. 
int distanceFromRoot(struct Node* root, int x) 
{ 
    if (root->key == x) 
        return 0; 
    else if (root->key > x) 
        return 1 + distanceFromRoot(root->left, x); 
    return 1 + distanceFromRoot(root->right, x); 
} 
  
// Returns minimum distance beween a and b. 
// This function assumes that a and b exist 
// in BST. 
int distanceBetween2(struct Node* root, int a, int b) 
{ 
    if (!root) 
        return 0; 
  
    // Both keys lie in left 
    if (root->key > a && root->key > b) 
        return distanceBetween2(root->left, a, b); 
  
    // Both keys lie in right 
    if (root->key < a && root->key < b) // same path 
        return distanceBetween2(root->right, a, b); 
  
    // Lie in opposite directions (Root is 
    // LCA of two nodes) 
    if (root->key >= a && root->key <= b) 
        return distanceFromRoot(root, a) +  
               distanceFromRoot(root, b); 
} 
  
// This function make sure that a is smaller 
// than b before making a call to findDistWrapper() 
int findDistWrapper(Node *root, int a, int b) 
{ 
   if (a > b) 
     swap(a, b); 
   return distanceBetween2(root, a, b);    
} 
  
// Driver code 
int main() 
{ 
    struct Node* root = NULL; 
    root = insert(root, 20); 
    insert(root, 10); 
    insert(root, 5); 
    insert(root, 15); 
    insert(root, 30); 
    insert(root, 25); 
    insert(root, 35); 
    int a = 5, b = 55; 
    cout << findDistWrapper(root, 5, 35); 
    return 0; 
}

//**************************************************

// C++ code to calculate maximum unique 
// element of every segment of array 
#include <bits/stdc++.h> 
using namespace std; 
  
void find_max(int A[], int N, int K) 
{ 
    // Storing counts of first K-1 elements 
    // Also storing distinct elements. 
    map<int, int> Count; 
    for (int i = 0; i < K - 1; i++) 
        Count[A[i]]++; 
    set<int> Myset; 
    for (auto x : Count) 
        if (x.second == 1) 
            Myset.insert(x.first); 
  
    // Before every iteration of this loop, 
    // we maintain that K-1 elements of current 
    // window are processed. 
    for (int i = K - 1; i < N; i++) { 
  
        // Process K-th element of current window 
        Count[A[i]]++; 
        if (Count[A[i]] == 1) 
            Myset.insert(A[i]); 
        else
            Myset.erase(A[i]); 
  
        // If there are no distinct 
        // elements in current window 
        if (Myset.size() == 0)  
            printf("Nothing\n"); 
          
        // Set is ordered and last element 
        // of set gives us maximum element. 
        else 
            printf("%d\n", *Myset.rbegin()); 
          
        // Remove first element of current  
        // window before next iteration. 
        int x = A[i - K + 1]; 
        Count[x]--; 
        if (Count[x] == 1) 
            Myset.insert(x); 
        if (Count[x] == 0) 
            Myset.erase(x); 
    } 
} 
  
// Driver code 
int main() 
{ 
    int a[] = { 1, 2, 2, 3, 3 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    int k = 3; 
    find_max(a, n, k); 
    return 0; 
} 

//****************************************************


// A C program to check for Identical BSTs without building the trees 
#include<stdio.h> 
#include<limits.h> 
#include<stdbool.h> 
  
/* The main function that checks if two arrays a[] and b[] of size n construct 
  same BST. The two values 'min' and 'max' decide whether the call is made for 
  left subtree or right subtree of a parent element. The indexes i1 and i2 are 
  the indexes in (a[] and b[]) after which we search the left or right child. 
  Initially, the call is made for INT_MIN and INT_MAX as 'min' and 'max' 
  respectively, because root has no parent. 
  i1 and i2 are just after the indexes of the parent element in a[] and b[]. */
bool isSameBSTUtil(int a[], int b[], int n, int i1, int i2, int min, int max) 
{ 
   int j, k; 
  
   /* Search for a value satisfying the constraints of min and max in a[] and  
      b[]. If the parent element is a leaf node then there must be some  
      elements in a[] and b[] satisfying constraint. */
   for (j=i1; j<n; j++) 
       if (a[j]>min && a[j]<max) 
           break; 
   for (k=i2; k<n; k++) 
       if (b[k]>min && b[k]<max) 
           break; 
  
   /* If the parent element is leaf in both arrays */
   if (j==n && k==n) 
       return true; 
  
   /* Return false if any of the following is true 
      a) If the parent element is leaf in one array, but non-leaf in other. 
      b) The elements satisfying constraints are not same. We either search 
         for left child or right child of the parent element (decinded by min 
         and max values). The child found must be same in both arrays */
   if (((j==n)^(k==n)) || a[j]!=b[k]) 
       return false; 
  
   /* Make the current child as parent and recursively check for left and right 
      subtrees of it. Note that we can also pass a[k] in place of a[j] as they 
      are both are same */
   return isSameBSTUtil(a, b, n, j+1, k+1, a[j], max) &&  // Right Subtree 
          isSameBSTUtil(a, b, n, j+1, k+1, min, a[j]);    // Left Subtree 
} 
  
// A wrapper over isSameBSTUtil() 
bool isSameBST(int a[], int b[], int n) 
{ 
   return isSameBSTUtil(a, b, n, 0, 0, INT_MIN, INT_MAX); 
} 
  
// Driver program to test above functions 
int main() 
{ 
   int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13}; 
   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13}; 
   int n=sizeof(a)/sizeof(a[0]); 
   printf("%s\n", isSameBST(a, b, n)? 
             "BSTs are same":"BSTs not same"); 
   return 0; 
} 

//******************************************************

// A recursive C program to find LCA of two nodes n1 and n2. 
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


max heap using STL

#include <bits/stdc++.h> 
using namespace std; 
  
// Driver code 
int main () 
{ 
    // Creates a max heap 
    priority_queue <int> pq; 
    pq.push(5); 
    pq.push(1); 
    pq.push(10); 
    pq.push(30); 
    pq.push(20); 
  
    // One by one extract items from max heap 
    while (pq.empty() == false) 
    { 
        cout << pq.top() << " "; 
        pq.pop(); 
    } 
  
    return 0; 
} 

***************************************************

min heap using STL

#include <bits/stdc++.h> 
using namespace std; 
  
// Driver code 
int main () 
{ 
    // Creates a min heap 
    priority_queue <int, vector<int>, greater<int> > pq; 
    pq.push(5); 
    pq.push(1); 
    pq.push(10); 
    pq.push(30); 
    pq.push(20); 
  
    // One by one extract items from min heap 
    while (pq.empty() == false) 
    { 
        cout << pq.top() << " "; 
        pq.pop(); 
    } 
  
    return 0; 
}

**************************************************
min heap all function 

#include<iostream> 
#include<climits> 
using namespace std; 
  
// Prototype of a utility function to swap two integers 
void swap(int *x, int *y); 
  
// A class for Min Heap 
class MinHeap 
{ 
    int *harr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap 
public: 
    // Constructor 
    MinHeap(int capacity); 
  
    // to heapify a subtree with the root at given index 
    void MinHeapify(int ); 
  
    int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
  
    // to extract the root which is the minimum element 
    int extractMin(); 
  
    // Decreases key value of key at index i to new_val 
    void decreaseKey(int i, int new_val); 
  
    // Returns the minimum key (key at root) from min heap 
    int getMin() { return harr[0]; } 
  
    // Deletes a key stored at index i 
    void deleteKey(int i); 
  
    // Inserts a new key 'k' 
    void insertKey(int k); 
}; 
  
// Constructor: Builds a heap from a given array a[] of given size 
MinHeap::MinHeap(int cap) 
{ 
    heap_size = 0; 
    capacity = cap; 
    harr = new int[cap]; 
} 
  
// Inserts a new key 'k' 
void MinHeap::insertKey(int k) 
{ 
    if (heap_size == capacity) 
    { 
        cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    } 
  
    // First insert the new key at the end 
    heap_size++; 
    int i = heap_size - 1; 
    harr[i] = k; 
  
    // Fix the min heap property if it is violated 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
} 
  
// Decreases value of key at index 'i' to new_val.  It is assumed that 
// new_val is smaller than harr[i]. 
void MinHeap::decreaseKey(int i, int new_val) 
{ 
    harr[i] = new_val; 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
} 
  
// Method to remove minimum element (or root) from min heap 
int MinHeap::extractMin() 
{ 
    if (heap_size <= 0) 
        return INT_MAX; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    } 
  
    // Store the minimum value, and remove it from heap 
    int root = harr[0]; 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    MinHeapify(0); 
  
    return root; 
} 
  
  
// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls extractMin() 
void MinHeap::deleteKey(int i) 
{ 
    decreaseKey(i, INT_MIN); 
    extractMin(); 
} 
  
// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && harr[l] < harr[i]) 
        smallest = l; 
    if (r < heap_size && harr[r] < harr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&harr[i], &harr[smallest]); 
        MinHeapify(smallest); 
    } 
} 
  
// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
} 
**************************************************************************
max heap deletion and insertion in c++


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int N,heap[11],capacity=10;
int parent(int k)
{
    return k/2;
}

void shiftup(int k) {
    while (k > 1 && heap[parent(k)] < heap[k])
    {
        swap(heap[parent(k)], heap[k]);

    k=parent(k);}
}

void ins(int num)
{
    if(N== capacity)
    {
        cout<<"Max CAPACITY REACHED"<<endl;
        return;

    }
    heap[++N]=num;
    shiftup(N);
}

int getmax()
{
    return heap[1];
}
void shiftdown(int k){
    while(2*k<=N)
    {
        int j=2*k;
        if(j<N && heap[j]<heap[j+1])j++;
        if (heap[k]>heap[j])
        break;
        swap(heap[k],heap[j]);
        k=j;

    }
}


int extractMax()
{
    if(N<1)
    {
        cout<<"trying to extract from empty heap"<<endl;
        return -1;
    }
    int MAX=heap[1];
    swap(heap[1],heap[N--]);
    shiftdown(1);
    return MAX;
}

void display()
{
    for(int i=1;i<=N;i++)
       cout<<heap[i]<<" ";
    cout<<endl;
}

int main()

{

    //array limit 10
    int a[30];
while(1) {
    cout << "\t\t\t\t************ Enter Choice ************" << endl;
    cout << "1. For getting maximum  big(1)\n2. FOr extract max  log(n)\n3. insert log(n)\n4. Display big(n)" << endl;
    cout << "Enter NO" << endl;
    int ch, num;
    cin >> ch;

    switch (ch) {

        case 1:
            cout << "Max ELemt" << getmax()<<endl;
            break;
        case 2:
        
            extractMax();
            break;
        case 3:
            cout << "Enter number" << endl;
            cin >> num;
            ins(num);
            break;
        case 4:
            display();
            break;
            
        default:
            exit(0);
    }
}


}
**************************************************
max heap with all its function but in java

public class MaxHeap { 
    private int[] Heap; 
    private int size; 
    private int maxsize; 
  
    // Constructor to initialize an 
    // empty max heap with given maximum 
    // capacity. 
    public MaxHeap(int maxsize) 
    { 
        this.maxsize = maxsize; 
        this.size = 0; 
        Heap = new int[this.maxsize + 1]; 
        Heap[0] = Integer.MAX_VALUE; 
    } 
  
    // Returns position of parent 
    private int parent(int pos) 
    { 
        return pos / 2; 
    } 
  
    // Below two functions return left and 
    // right children. 
    private int leftChild(int pos) 
    { 
        return (2 * pos); 
    } 
    private int rightChild(int pos) 
    { 
        return (2 * pos) + 1; 
    } 
  
    // Returns true of given node is leaf 
    private boolean isLeaf(int pos) 
    { 
        if (pos >= (size / 2) && pos <= size) { 
            return true; 
        } 
        return false; 
    } 
  
    private void swap(int fpos, int spos) 
    { 
        int tmp; 
        tmp = Heap[fpos]; 
        Heap[fpos] = Heap[spos]; 
        Heap[spos] = tmp; 
    } 
  
    // A recursive function to max heapify the given 
    // subtree. This function assumes that the left and 
    // right subtrees are already heapified, we only need 
    // to fix the root. 
    private void maxHeapify(int pos) 
    { 
        if (isLeaf(pos)) 
            return; 
  
        if (Heap[pos] < Heap[leftChild(pos)] ||  
            Heap[pos] < Heap[rightChild(pos)]) { 
  
            if (Heap[leftChild(pos)] > Heap[rightChild(pos)]) { 
                swap(pos, leftChild(pos)); 
                maxHeapify(leftChild(pos)); 
            } 
            else { 
                swap(pos, rightChild(pos)); 
                maxHeapify(rightChild(pos)); 
            } 
        } 
    } 
  
    // Inserts a new element to max heap 
    public void insert(int element) 
    { 
        Heap[++size] = element; 
  
        // Traverse up and fix violated property 
        int current = size; 
        while (Heap[current] > Heap[parent(current)]) { 
            swap(current, parent(current)); 
            current = parent(current); 
        } 
    } 
  
    public void print() 
    { 
        for (int i = 1; i <= size / 2; i++) { 
            System.out.print(" PARENT : " + Heap[i] + " LEFT CHILD : " + 
                      Heap[2 * i] + " RIGHT CHILD :" + Heap[2 * i + 1]); 
            System.out.println(); 
        } 
    } 
  
    // Remove an element from max heap 
    public int extractMax() 
    { 
        int popped = Heap[1]; 
        Heap[1] = Heap[size--]; 
        maxHeapify(1); 
        return popped; 
    } 
  
    public static void main(String[] arg) 
    { 
        System.out.println("The Max Heap is "); 
        MaxHeap maxHeap = new MaxHeap(15); 
        maxHeap.insert(5); 
        maxHeap.insert(3); 
        maxHeap.insert(17); 
        maxHeap.insert(10); 
        maxHeap.insert(84); 
        maxHeap.insert(19); 
        maxHeap.insert(6); 
        maxHeap.insert(22); 
        maxHeap.insert(9); 
  
        maxHeap.print(); 
        System.out.println("The max val is " + maxHeap.extractMax()); 
    } 
}

***************************************************
heap sort 


#include <iostream> 
  
using namespace std; 
  
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  
/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
}

**************************************************
tree

*****
normal binary tree insertion

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
***************************************************
insertion and deletion in binary tree

# include <stdio.h>
# include <malloc.h>

struct node
{
	int info;
	struct node *lchild;
	struct node *rchild;
}*root;



void find(int item,struct node **par,struct node **loc)
{
	struct node *ptr,*ptrsave;

	if(root==NULL)  /*tree empty*/
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->info) /*item is at root*/
	{
		*loc=root;
		*par=NULL;
		return;
	}
	/*Initialize ptr and ptrsave*/
	if(item<root->info)
		ptr=root->lchild;
	else
		ptr=root->rchild;
	ptrsave=root;

	while(ptr!=NULL)
	{
		if(item==ptr->info)
		{       *loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->info)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	 }/*End of while */
	 *loc=NULL;   /*item not found*/
	 *par=ptrsave;
}/*End of find()*/

void insert(int item)
{       struct node *tmp,*parent,*location;
	find(item,&parent,&location);
	if(location!=NULL)
	{
		printf("Item already present");
		return;
	}

	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	tmp->lchild=NULL;
	tmp->rchild=NULL;

	if(parent==NULL)
		root=tmp;
	else
		if(item<parent->info)
			parent->lchild=tmp;
		else
			parent->rchild=tmp;
}/*End of insert()*/


void case_a(struct node *par,struct node *loc )
{
	if(par==NULL) /*item to be deleted is root node*/
		root=NULL;
	else
		if(loc==par->lchild)
			par->lchild=NULL;
		else
			par->rchild=NULL;
}/*End of case_a()*/

void case_b(struct node *par,struct node *loc)
{
	struct node *child;

	/*Initialize child*/
	if(loc->lchild!=NULL) /*item to be deleted has lchild */
		child=loc->lchild;
	else                /*item to be deleted has rchild */
		child=loc->rchild;

	if(par==NULL )   /*Item to be deleted is root node*/
		root=child;
	else
		if( loc==par->lchild)   /*item is lchild of its parent*/
			par->lchild=child;
		else                  /*item is rchild of its parent*/
			par->rchild=child;
}/*End of case_b()*/

void case_c(struct node *par,struct node *loc)
{
	struct node *ptr,*ptrsave,*suc,*parsuc;

	/*Find inorder successor and its parent*/
	ptrsave=loc;
	ptr=loc->rchild;
	while(ptr->lchild!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->lchild;
	}
	suc=ptr;
	parsuc=ptrsave;

	if(suc->lchild==NULL && suc->rchild==NULL)
		case_a(parsuc,suc);
	else
		case_b(parsuc,suc);

	if(par==NULL) /*if item to be deleted is root node */
		root=suc;
	else
		if(loc==par->lchild)
			par->lchild=suc;
		else
			par->rchild=suc;

	suc->lchild=loc->lchild;
	suc->rchild=loc->rchild;
}/*End of case_c()*/
int del(int item)
{
	struct node *parent,*location;
	if(root==NULL)
	{
		printf("Tree empty");
		return 0;
	}

	find(item,&parent,&location);
	if(location==NULL)
	{
		printf("Item not present in tree");
		return 0;
	}

	if(location->lchild==NULL && location->rchild==NULL)
		case_a(parent,location);
	if(location->lchild!=NULL && location->rchild==NULL)
		case_b(parent,location);
	if(location->lchild==NULL && location->rchild!=NULL)
		case_b(parent,location);
	if(location->lchild!=NULL && location->rchild!=NULL)
		case_c(parent,location);
	free(location);
}/*End of del()*/

int preorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return 0;
	}
	if(ptr!=NULL)
	{
		printf("%d  ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}/*End of preorder()*/

void inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder()*/

void postorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ",ptr->info);
	}
}/*End of postorder()*/

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}/*End of if*/
}/*End of display()*/
main()
{
	int choice,num;
	root=NULL;
	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n");
		printf("5.Postorder Traversal\n");
		printf("6.Display\n");
		printf("7.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			preorder(root);
			break;
		 case 5:
			postorder(root);
			break;
		 case 6:
			display(root,1);
			break;
		 case 7:
            break;
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*
**************************************************
making a traversal tree


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
    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node* root = insertLevelOrder(arr, root, 0, n); 
    inOrder(root); 
    cout<<endl;
    labelorder(root);
    
}
**************************************************
k th ancester of a node

#include<bits/stdc++.h>
#include <queue> 
using namespace std;

	struct node{
		int data;
		node *left, *right;
		
	}*root=NULL,*p;
	node *newNode(int data){
		node* newnode= new node;
		newnode->data=data;
		newnode->left=newnode->right=NULL;
		return newnode;
	}
		queue <node *> qe;

	void labelorder(node *ro,int a[]){

	if(ro==NULL)
		return;
		qe.push(ro);
		while(!qe.empty()){
			// my testing
			node *temp= qe.front();
			qe.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL){
			 a[temp->left->data]=temp->data;
	    qe.push(temp->left); 
}
	    if(temp->right!=NULL){
	    	
	       a[temp->right->data]=temp->data;
	    qe.push(temp->right);
	    
}
	    }
	   cout<<endl;
 for(int i=1;i<8;i++){
	cout<<a[i]<<"  ";
}
	

}

void path(node *ro){

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
	
	int main(){
		
root=newNode(1);
root->left=newNode(2);
root->right=newNode(3);
root->left->left=newNode(4);
root->left->right=newNode(5);
root->left->left->left=newNode(7);
root->right->left=newNode(6);
int n=8;
int a[8];
a[1]=-1;
labelorder(root,a);
cout<<endl;
int val=7,k=2;
int cnt=0;
//cout<<"gfd123";

//cout<<"gfd";
 while(val!=-1){
 	val=a[val];
 	if(++cnt==k)
 	break;
 }
 
	cout<<val;


	}
***************************************************
skewed tree

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

            q.push(var);
            continue;
        }
        int var1=0,var2=0;
        if(da->left!=NULL)
        {
            q.push(da->left);
            var1=1;
        }
        if(da->right!=NULL)
        {
            q.push(da->right);
            var2=1;
        }
        if(var1==1 && var2==1)
        {
            cout<<"NOT SKEWED TREE"<<endl;
            return ;
        }
    }
    cout<<"SKEWED TREE"<<endl;
}
int main()
{
    node* root = newNode(1);
    root->right = newNode(2);
    root->right->right = newNode(3);
    root->right->right->right = newNode(4);
    levelorder(root);

    return 0;
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

***************************************************

printing tree level wise

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
