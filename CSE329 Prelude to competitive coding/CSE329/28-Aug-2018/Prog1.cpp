// Stack using Doubley Linked LIsts.
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next,*prev;
}*top=NULL;

int push(int num)
{
    node *newnode = new node;
    if(top==NULL) {
        newnode->data = num;
        newnode->next = NULL;
        newnode->prev = NULL;
        top = newnode;
    }
    else {
        newnode->data = num;
        newnode->prev = top;
        newnode->next = NULL;
        top = newnode;
    }
    return 0;
}
int pop()
{
    if(top->prev==NULL) {
        cout<<"Underflow\n";
    }
    else {
        top = top->prev;
        top->next = NULL;
    }
}
int peek()
{
    if(top!=NULL) {
        cout<<"Top Element : "<<top->data<<"\n";
    }
    else {
        cout<<"No Elements in Stack.\n";
    }
}
int main()
{
    int opt,num;
    cout<<"1.Push\n2.Pop\n3.Peek\n4.Exit\n>> ";
    cin>>opt;
    switch(opt) {
        case 1  :   cout<<"Enter Number to Push : ";
                    cin>>num;
                    push(num);
                    break;
        case 2  :   pop();
                    break;
        case 3  :   peek();
                    break;
        case 4  :   exit(0);
                    break;
        default :   cout<<"Invalid Option.";
    }
    main();
    return 0;
}
