exponent program

#include<iostream>
using namespace std;

long N = 1000000007L;

long exponentiation(long base, long exp) 
{ 
    long t = 1L; 
    while (exp > 0) { 
        if (exp % 2 != 0) 
            t = (t * base) % N; 

        base = (base * base) % N; 
        exp /= 2; 
    } 
    return t % N; 
} 

int main(){
    cout<<exponentiation(5,10000)<<endl;
}
**********************************************************************


gcd of a number




// C++ program to find GCD of two numbers 
#include <iostream> 
using namespace std; 
// Recursive function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 
   
// Driver program to test above function 
int main() 
{ 
    int a = 98, b = 56; 
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b); 
    return 0; 
}

*************************************************************************

prime factor 




int main()
{
    int i, j, num, isPrime;

    /* Input a number from user */
    printf("Enter any number to print Prime factors: ");
    scanf("%d", &num);

    printf("All Prime Factors of %d are: \n", num);

    /* Find all Prime factors */
    for(i=2; i<=num; i++)
    {
        /* Check 'i' for factor of num */
        if(num%i==0)
        {
            /* Check 'i' for Prime */
            isPrime = 1;
            for(j=2; j<=i/2; j++)
            {
                if(i%j==0)
                {
                    isPrime = 0;
                    break;
                }
            }

            /* If 'i' is Prime number and factor of num */
            if(isPrime==1)
            {
                printf("%d, ", i);
            }
        }
    }

    return 0;
}



*****************************************************************************
check wheather the number is prime or not







#include <stdio.h>
int main()
{
    int n, i, flag = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for(i = 2; i <= n/2; ++i)
    {
        // condition for nonprime number
        if(n%i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (n == 1) 
    {
      printf("1 is neither a prime nor a composite number.");
    }
    else 
    {
        if (flag == 0)
          printf("%d is a prime number.", n);
        else
          printf("%d is not a prime number.", n);
    }
    
    return 0;
}
**************************************************************************
hackeranck code






#include <bits/stdc++.h> 

using namespace std; 

typedef long long ll;


const int MAX = 100000;


ll r[MAX + 1]; 

bool p_no[MAX + 1]; 
 
void primes_no() 
{ 
 
    
memset(p_no, true, sizeof(p_no)); 
  
   
 for (ll p = 2; p  <= sqrt(MAX); p++) 
	{ 

	if (p_no[p] == true) 
	{ 
     
   for (ll i = p * 2; i <= MAX; i += p) 
              
  p_no[i] = false; 
    } 
    } 
} 


void values()
{
	for(ll j=2;j<MAX;j++)
	{
	
	if(p_no[j])
		{
			
	r[j]=r[j-1]+1;
		}
	
	else
		{
		
	r[j]=r[j-1];
		}
	
}
}
 


 
int main()

{
	
primes_no();
	
values();
	
ll n;
	
cin>>n;
	
while(n--)
	{
		
ll a,b,count;
		
cin>>a>>b;
		
count=r[b]-r[a-1];
		
cout<<count<<endl;

	}

}



******************************************************************************

k jagged number 


# include <bits/stdc++.h> 
using namespace std; 
  
// Returns true if n is k rough else false 
bool isKRough(int n, int k) 
{ 
    // If n is even, then smallest prime 
    // factor becomes 2. 
    if (n % 2 == 0) 
        return (k <= 2); 
  
    // n must be odd at this point.  So we 
    // can skip one element (Note i = i +2) 
    for (int i = 3; i*i <= n; i = i+2) 
        if (n%i == 0) 
            return (i >= k); 
  
   return (n >= k); 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int n = 75, k = 3; 
    if (isKRough(n, k)) 
        cout << n << " is a "
             << k << "-rough number\n"; 
    else
        cout << n << " is not a "
             << k << "-rough number\n"; 
    return 0; 
} 

**********************************************************************
stormer number

#include <iostream> 
using namespace std; 
  
 int maxPrimeFactors(int n)  
{  
    // Initialize the maximum  
    // prime factor variable  
    // with the lowest one  
    int maxPrime = -1;  
  
    // Print the number of  
    // 2's that divide n  
    while(n % 2 == 0)  
    {  
        maxPrime = 2;  
        n /= 2;  
    }  
  
    // n must be odd at this  
    // point, thus skip the  
    // even numbers and iterate  
    // only for odd integers  
    for(int i = 3; i < (int)(n * 1 /  
                2 + 1); i += 2)  
        while(n % i == 0)  
        {  
            maxPrime = i;  
            n /= i;  
        }  
  
    // This condition is to handle  
    // the case when n is a prime  
    // number greater than 2  
    if (n > 2)  
        maxPrime = n;  
  
    return (int)(maxPrime);  
}  
  
// Function to generate  
// Stormer Numbers  
 int stormer(int n)  
{  
    int i = 1;  
      
    // Stores the number of  
    // Stormer numbers found  
    int count = 0;  
    while(count < n)  
    {  
        int t = i * i + 1;  
        if (maxPrimeFactors(t) >= 2 * i)  
        {  
            cout << i ; 
            cout <<" ";  
            count += 1;  
        }  
        i += 1;  
    }  
    return i;  
}  
  
    // Driver Code  
int main() { 
  
    int n = 10;  
    stormer(n);  
  
    }
********************************************************************************


navive search



// C program for Naive Pattern Searching algorithm 
#include <stdio.h> 
#include <string.h> 
  
void search(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 
  
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            printf("Pattern found at index %d \n", i); 
    } 
} 
  
/* Driver program to test above function */
int main() 
{ 
    char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 
    search(pat, txt); 
    return 0; 
} 


**************************************************************************

bineary search




#include<bits/stdc++.h>
using namespace std;

int bin(int a[],int low,int high,int n,int val){
	if(low<=high){
	int mid=low+(high-low)/2;
	if(a[mid]==val)
	return mid;
	else if(val>a[mid])
	 return bin(a,mid+1,high,n,val);
	 else
	return bin(a,low,mid-1,n,val);
	
}
return -1;

}

int main(){
	
	int a[]={1,2,3,4,5};
	int c=bin(a,1,5,5,6);
	cout<<c;
	
}


****************************************************************************

join rope problem


// join rope problem
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*int main()
{
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int result=0;
    for(i=0;i<n;i++)
    {
        a[i+1]=a[i]+a[i+1];
        a[i]=0;
        result+=a[i+1];
        sort(a+i+1,a+n);
    }
    cout<<result<<endl;
    return 0;
}
*/
/*
int join_ropes(int a[],int n)
{
    int total=0;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        v.push_back(a[i]);
    }
    while(v.size()>1)
    {
        sort(v.begin(),v.end());
        total+=v[0]+v[1];
        v.push_back(v[0]+v[1]);
        v.erase(v.begin(),v.begin()+2);
    }
    return total;

}
int main()
{


    int a[]={2,5,4,6};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<join_ropes(a,n);
}

******************************************************************************


fractional knapack problem




/*
struct Job
{
    int value,weight;
};
bool cmp(Job a,Job b){return a.value*b.weight>b.value*a.weight; }
double max_value(Job arr[],int n,int w){
    double total=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=w){
            w=w-arr[i].weight;
            total+=arr[i].value;
        }
        else if(w>0)
        {
            total+=((double)arr[i].value/arr[i].weight)*w;
            w=0;
        }
    }
    return total;
}

int main()
{
    Job arr[]={{100,10},{50,20},{120,30}};
    int n=sizeof(arr)/sizeof(arr[0]);
    int w=50;
    cout<<max_value(arr,n,w);
}
 



**************************************************************************

linked list



// A complete working C program to demonstrate all insertion methods 
// on Linked List 
#include <stdio.h> 
#include <stdlib.h> 
  
// A linked list node 
struct Node 
{ 
  int data; 
  struct Node *next; 
}; 
  
/* Given a reference (pointer to pointer) to the head of a list and  
   an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    /* 2. put in the data  */
    new_node->data  = new_data; 
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
  
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
/* Given a node prev_node, insert a new node after the given  
   prev_node */
void insertAfter(struct Node* prev_node, int new_data) 
{ 
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) 
    { 
      printf("the given previous node cannot be NULL"); 
      return; 
    } 
  
    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
  
    /* 3. put in the data  */
    new_node->data  = new_data; 
  
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next; 
  
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node; 
} 
  
/* Given a reference (pointer to pointer) to the head 
   of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node *last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->data  = new_data; 
  
    /* 3. This new node is going to be the last node, so make next of 
          it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
  
    /* 6. Change the next of last node */
    last->next = new_node; 
    return; 
} 
  
// This function prints contents of linked list starting from head 
void printList(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf(" %d ", node->data); 
     node = node->next; 
  } 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
  /* Start with the empty list */
  struct Node* head = NULL; 
  
  // Insert 6.  So linked list becomes 6->NULL 
  append(&head, 6); 
  
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL 
  push(&head, 7); 
  
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL 
  push(&head, 1); 
  
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL 
  append(&head, 4); 
  
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL 
  insertAfter(head->next, 8); 
  
  printf("\n Created Linked list is: "); 
  printList(head); 
  
  return 0; 
} 
*********************************************************************************
stl function  

Functions used with List :
front() – Returns the value of the first element in the list
back() – Returns the value of the last element in the list
push_front(g) – Adds a new element ‘g’ at the beginning of the list
push_back(g) – Adds a new element ‘g’ at the end of the list
pop_front() – Removes the first element of the list, and reduces size of the list by 1
pop_back() – Removes the last element of the list, and reduces size of the list by 1
begin() – Returns an iterator pointing to the first element of the list
end() – Returns an iterator pointing to the theoretical last element which follows the last element
empty() – Returns whether the list is empty(1) or not(0)
insert() – Inserts new elements in the list before the element at a specified position
erase() – Removes a single element or a range of elements from the list
assign() – Assigns new elements to list by replacing current elements and resizes the list
remove() – Removes all the elements from the list, which are equal to given element
reverse() – Reverses the list
size() – Returns the number of elements in the list
sort() – Sorts the list in increasing order


**********************************************************************************
normal eucler is GCD only
**********************************************************************************
extented eucler form

#include <stdio.h> 
  
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  printf("%d   %d\n",*x,*y);
    return gcd; 
} 
  
// Driver Program 
int main() 
{ 
    int x, y; 
    int a = 30, b = 20; 
    int g = gcdExtended(a, b, &x, &y); 
    printf("gcd(%d, %d) = %d", a, b, g); 
    return 0; 
}




Job selection problem using time shedueling





/*
struct Job
{
    int id,start,finish;
};
bool cmp(Job a,Job b)
{
    return a.finish<b.finish;
}
void max_jobs(Job arr[],int n)
{
    int res=1,j=0;
    cout<<arr[0].id<<" ";
    for(int i=1;i<n;i++)
    {
        if(arr[i].start>=arr[j].finish){
            cout<<arr[i].id<<" ";
            res++;
            j=i;
        }
    }
    cout<<endl<<res;
}
int main()
{
    Job arr[]={{1,0,10},{2,10,20},{3,15,30},{4,30,35}};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,cmp);
  //  cout<<"sandip"<<arr<<"fg123"<<endl;
  cout<<"sandip";
    for(int x=0;x<4;x++)
    cout<<arr[x].id<<"   "<<arr[x].start<<"   "<<arr[x].finish<<endl;
    //cout<<"sudip";
    max_jobs(arr,n);
    return 0;
}


*******************************************************************************

job sequence




#include<bits/stdc++.h>
using namespace std;
/*
Job  End-time Profit
J1      3      16
J2      1       4
J3      3       3
J4      1       2
*/

struct Job
{
    int id,etime,profit;
};
bool cmp(Job a,Job b)
{
    return a.profit>b.profit;
}
void seqence(Job a[],int n)
{
    int slot[n],seq[n];
    for(int i=0;i<n;i++)
        slot[i]=false;
    for(int i=0;i<n;i++)
    {
        for(int j=a[i].etime-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                slot[j]=true;
                seq[j]=i;
                break;
            }
        }
    }
    cout<<"Job sequence to get maximum profit"<<endl;
    for(int i=0;i<n;i++)
    {
        if(slot[i])
            cout<<a[seq[i]].id<<" ";
    }

}
int main()
{
    Job arr[]={{1,3,16},{2,1,4},{3,3,3},{4,1,2}};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,cmp);
    seqence(arr,n);
    return 0;
}
*******************************************************************
how many bits are required to change from one number to another

#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int x = a ^ b;
    int count=0;
    while(x)
    {
        count += x & 1;
        x >>=1;
    }
    cout<<"Count : "<<count<<"\n";
}
********************************************************************

making of a queue

// Queue using Singly LinkedList.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *nxtptr;
}*front=NULL,*rear=NULL;

int enqueue(int num)
{
    node *newnode = new node;
    newnode->data = num;
    newnode->nxtptr = NULL;

    if(rear==NULL) {
        front = rear = newnode;    
    }
    else {
        rear->nxtptr = newnode;
        rear = newnode;
    }
}
int dequeue()
{
    if(front==NULL) {
        cout<<"No Element in Queue.\n";
    }
    else {
        node *curr = front;
        front = front->nxtptr;
        if(front==NULL)
            rear==NULL;
        delete curr;
    }
}
int showfront()
{
    if(front==NULL)
        cout<<"-1\n";
    cout<<front->data<<"\n";
}
int show()
{
    node *ptr = front;
    while(ptr!=NULL) {
        cout<<ptr->data<<" ";
        ptr = ptr->nxtptr;
    }
    cout<<"\n";
}

int main()
{
    int opt,num;
    
    while(1) {
        cout<<"\n1.Enqueue\n2.Dequeue\n3.Front\n4.Show\n5.Exit\n>> ";
        cin>>opt;
        switch(opt) {
            case 1 :    cout<<"Enter a number to Enqueue : ";
                        cin>>num;
                        enqueue(num);
                        break;
            case 2 :    dequeue();
                        break;
            case 3 :    showfront();
                        break;
            case 4 :    show();
                        break;
            case 5 :    exit(0);
                        break;
            default :   cout<<"Invalid Option.\n";
        }
    }
}
*****************************************************************************
queue with priority

// Priority Queue using Linked LIst.
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
struct Node
{
    int data,priority;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int data, int priority)
{
    Node *temp = new Node;
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
        if(rear == NULL)
            front = rear = temp;
        else {
            Node *ptr = front;
            while ((ptr->next != NULL) && (ptr->data > temp->data))
                ptr = ptr->next;
            if(ptr == front) {
                temp->next = front;
                front = temp;
            }
            else {
                temp->next = ptr->next;
                ptr->next = temp;
            }
        }
        cout<<front->data<<endl;
    }

void dequeue()
{
    front = front->next;
    cout<<front->data<<endl;
}

void getfront()
{
    cout<<front->data<<"\n";
}


int main()
{
    int opt;
    cout<<"\n1.Enqueue\n2.Dequeue\n3.Front\n4.Exit\n>> ";
    cin>>opt;
    switch(opt) {
        case 1 :    int num,priority;
                    cout<<"Enter Number and Priority : ";
                    cin>>num>>priority;
                    enqueue(num,priority);
                    break;
        case 2 :    dequeue();
                    break;
        case 3 :    getfront();
                    break;
        case 4 :    exit(0);
                    break;
        default :   cout<<"Invalid Option\n";
    }
    main();
}
**************************************************************************************
longest sub sequence

 
int max(int a, int b); 
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n ) 
{ 
   if (m == 0 || n == 0) 
     return 0; 
   if (X[m-1] == Y[n-1]) 
     return 1 + lcs(X, Y, m-1, n-1); 
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 
  
/* Utility function to get max of 2 integers */
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
/* Driver program to test above function */
int main() 
{ 
  char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
  
  int m = strlen(X); 
  int n = strlen(Y); 
  
  printf("Length of LCS is %d", lcs( X, Y, m, n ) ); 
  
  return 0; 
} 
***********************************************************

