// LinkedList
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *nextptr;
}*startNode = NULL;

int main()
{
    int n;
    cout<<"Enter Size Of LinkedList : ";
    cin>>n;
    struct Node *currpointer = startNode;
    cout<<"Enter Elements in it : ";
    for(int i=0;i<n;i++)
    {
        struct Node *newnode = new struct Node;
        cout<<"Hello\n";
        currpointer->nextptr = newnode;         // Error In This Line
        cout<<"Hello\n";
        cin>>currpointer->data;
        cout<<"Hello\n";
        currpointer = currpointer->nextptr;
    }

    currpointer = startNode;
    for(int i=0;i<n;i++)
    {
        cout<<currpointer->data<<" ";
        currpointer = currpointer->nextptr;
    }
    cout<<"\n";
}