
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


struct node{
	int info;
	struct node *link;
}*start=NULL,*rear=NULL;

void add1(int p){
	node *newnode=new node;
newnode->info=NULL;
newnode->info=p;
if(rear==NULL){

start=rear=newnode;
}else
{
	rear=rear->link=newnode;
	rear=newnode;
	
}
}
int  top1(){
	if(start==NULL)
	return -1;
	return start->info;
}
int dl()
{
	if(start== NULL)
		return -1;
	node *curr=start;
	start=start->link;	
	if(start==NULL){
		rear=NULL;
		int data=curr->info;
		delete curr;
		return data;
	}
	
}
int main(){
/*	
start=(struct node*) malloc (sizeof(struct node));	
	ptr=start;
	for(int i=1;i<=5;i++){
		cin>>ptr->info;
			ptr->link=(struct node*) malloc (sizeof(struct node));
	pre=ptr;
	ptr=ptr->link;
	}
	pre->link=NULL; 
		
	
		ptr=start;
	int w=1;
	while(ptr!=NULL)
	{
		printf("%d",ptr->info);
		ptr=ptr->link;
		w++;
	}
	add1();
	*/
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
			add1(p);
			break;
			case 2:
				cout<< "deleted item is  "<<dl()<<endl;
		break;
		case 3:
			cout<<"front element is "<<endl;
			cout<<top1()<<endl;
			break;
			case 4:
				exit(0);
				break;
		
		
		
	}}
	return 0;

}
/*
// with init function
queue<int> q;
for(int i=1;i<=10;i++)
{
	q.push(i);
	while(q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
	cout<<q.size()<<endl;
}


*/
/*
void add(int data){
node *newnode=new node;
newnode->next=NULL;
newnode->info=data;
if(head==NULL)
head=newnode;
else
{
node *curr=head;
while(curr->next!=NULL)
curr=curr->next;
curr->next=newnode;

}	
	
	
	
}

void display(){
	if(head==NULL)
	{
		cout<<"empty list";
		return;}
		else{
			node *curr=head;
			while(curr!=NULL)
			{cout<<curr->data<<endl;
			curr=curr->next;
		}
}

int main(){
int data,ch;
while(1){
	case 1:
		cout<<"ENTER DATA"<<endl;
		cin>>data;
		add(data);
		break;
	case 2:
		display();
		break;
	case 3:
		exit(0);
	}




}
*/
