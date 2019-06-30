#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
struct node{
	int info;
	struct node *link;
}*start,*pre,*ptr;

void pop(){
	
	
}

void push(){
	struct node *temp, *p;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;          
    } 
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Element Inserted at beginning"<<endl;
	
}

int main(){
	
	
	int ch,data;
	int *top;

start=(struct node*) malloc (sizeof(struct node));	
	ptr=start;
	for(int i=1;i<=5;i++){
		cin>>ptr->info;
			ptr->link=(struct node*) malloc (sizeof(struct node));
	pre=ptr;
	ptr=ptr->link;
	}
	pre->link=NULL; 
	
	cout<<"1. for push"<<endl;
	cout<<"2. for pop"<<endl;
	cout<<"3. for top"<<endl;
	cout<<"4. for exit"<<endl;
	cout<<"enter your choice"<<endl;
	cin>>ch;
		switch(ch){
		case 1:
		push();
		top=start;
		break;
		case 2:
		pop();
		
		break;
		case 4:
		exit(0);		
		break;
	}
	
	
	
}

*/


struct node{
	int data;
	struct node *next;
}*head=NULL,*tos=NULL;

void push(int data){
	node *newnode=new node;
	newnode->data=data;
newnode->next=NULL;
if(head==NULL)
	head=tos=newnode;
	else
{
/*	node *curr=head;
	while(curr->next!=NULL)
		curr=curr->next;*/
		curr->next=newnode;
		tos=tos->next;
}

}
int top(){
	if(tos==NULL);
	return -1;
	return tos->data;
}

int pop(){
	if(head==NULL)
	return -1;
	else
	{
		int data=tos->data;
		node *curr=head,*prev=head;
		if(tos==head){
			curr=tos;
			delete curr;
			return data;
			
		}
		while(curr->next != NULL)
		{
			prev=curr;
			curr=curr->next;
		}
		prev->next =NULL;
	}
	
}




