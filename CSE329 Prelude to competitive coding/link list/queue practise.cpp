#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;
	
}*front=NULL,*rear=NULL;
void enque(int p){
	if(rear== NULL && front==NULL){
	node *newnode=new node;
	newnode->next=NULL;
	newnode->data=p;
	front=rear=newnode;
	}
else
{	node *newnode=new node;
	newnode->next=NULL;
	newnode->data=p;
		rear=rear->next=newnode;
	rear=newnode;
	
}	
	
}
int deque1()
{
	if(front==NULL){
	return -1;
	//	cout<<"-1"<<endl;
	}
	int e;
	node *cur;
	e=front->data;
	cur=front;
	front=front->next;
	if(front==NULL)
	{  rear=NULL;
	//	int e=cur->data;
		delete cur;
		return e;
	}
}
int top1(){
	if(front==NULL){
		return -1;
	}
	else
	{
		return front->data;
	}
}

int main()
{
	while(1){
	
	cout<<"1. for enque"<<endl;
	cout<<"2. for deque"<<endl;
	cout<<"3. for front"<<endl;
	cout<<"4. for exit"<<endl;
	cout<<"enter your choice"<<endl;
	int ch;
	cin>>ch;
	switch (ch){
		case 1:
			cout<<"enter the data u want to enter"<<endl;
			int p;
			cin>>p;
			enque(p);
			break;
			case 2:cout<<"the deleted item is"<<endl;
			cout<<deque1()<<endl;
			break;
			case 3:
				cout<<"the top element is  ";
				cout<<top1()<<endl;
			break;
			case 4:
			exit(0);
			break;
						
		
		
		
		
		
	}
}
}
