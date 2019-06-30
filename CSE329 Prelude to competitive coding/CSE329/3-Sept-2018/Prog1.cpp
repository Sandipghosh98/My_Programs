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
