// Circular Queue using LL.
#include<iostream>
using namespace std;
struct node {
    int data;
    node *nxtptr;
}*rear=NULL;

void enqueue(int data)
{
    node *newnode = new node;
    newnode->data = data;
    if(rear==NULL) {
        newnode->nxtptr = newnode;
        rear=newnode;
    }
    else {
        newnode->nxtptr = rear->nxtptr;
        rear->nxtptr = newnode;
        rear = newnode;
    }
}
int dequeue()
{
    
}
int showfront()
{
    if(rear==NULL)
        return -1;
    return rear->data;
}

int main()
{

}