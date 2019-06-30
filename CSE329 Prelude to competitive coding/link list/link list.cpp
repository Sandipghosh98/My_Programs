
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


struct node{
	int info;
	struct node *link;
}*start,*pre,*ptr;

void add1(){
	node *newnode=new node;
newnode->next=NULL;
}

int main(){
	
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
	
	
	
	return 0;

}
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
