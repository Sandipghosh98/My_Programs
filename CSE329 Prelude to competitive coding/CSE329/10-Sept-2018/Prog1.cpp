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
