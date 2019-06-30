#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
}*front=NULL,*rear=NULL;

int enqueue(int num) {
    node *newnode = new node;
    newnode->data = num;
    newnode->next = NULL;    
    if(front==NULL && rear==NULL) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;    
    }
}

int dequeue()
{
    if(front == NULL)
        cout<<"Underflow";
    else
        front = front->next;
}

void showqueue()
{
    node *ptr = front;
    while(ptr != NULL) {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<"\n\n";
}
int main()
{
    int opt,num;
    cout<<"1.Enqueue\n2.Dequeue\n3.ShowQueue\n4.Exit\n>> ";
    cin>>opt;
    switch(opt) {
        case 1  :   cout<<"Enter a Number : ";
                    cin>>num;
                    enqueue(num);
                    break;
        case 2  :   dequeue();
                    break;
        case 3  :   showqueue();
                    break;
        case 4  :   exit(0);
                    break;
        default :   cout<<"Invalid Option.";
    }
    main();

    return 0;
}