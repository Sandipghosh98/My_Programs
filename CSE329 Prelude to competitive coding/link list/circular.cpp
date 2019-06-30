#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


struct node{
	int data;
	struct node *next;
}*start=NULL,*tail=NULL,*ptr;

void add(int data){
		node *newnode=new node;
//rear=rear->link=newnode;
newnode->data=data;
if(tail==NULL){

newnode->next=newnode;
tail=newnode;
}else
{	newnode->next=tail->next;
	tail->next=newnode;
	tail=newnode;
	
}}
int front()
{
	if(tail==NULL)
		return -1;
	return tail->next->data;
	

}

int dq(){
	if (tail==NULL)
		return -1;
	node *curr=tail->next;
	int data=curr->data;
	if(tail->next==tail){
		tail=NULL;}
	else
	tail->next=tail->next->next;
	delete curr;
	return data;
	
	
}





int main(){
	start=(struct node*) malloc (sizeof(struct node));
	
	
	
		while(1){
	
	cout<<"1. for enqueue "<<endl;
	cout<<"2. for dequeue "<<endl;
	cout<<"3. for front element "<<endl;
	cout<<"4. for exit "<<endl;
	cout<<" enter your choice"<<endl;
	int ch,p;
	cin>>ch;
	switch(ch){
		
		case 1:
			cout<< "enter the data u want to insert"<<endl;
			 cin>>p;
			add(p);
			break;
			case 2:
				cout<< "deleted item is  "<<dq()<<endl;
		break;
		case 3:
			cout<<"front element is "<<endl;
			cout<<front()<<endl;
			break;
			case 4:
				exit(0);
				break;
		
	}
	
}
}
