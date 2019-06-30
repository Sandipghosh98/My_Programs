#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	int pr;
	struct node *next; 
}*head=NULL,*cur;

int del(){
	if(head==NULL)
	return -1;
	cur=head;
	int t=cur->data;
	head=head->next;
		delete cur;
		return t;
/* if(head->next==NULL){
		head=NULL;
		
		delete cur;
		return t;
		
	}
	else{
		int t=head->data;
		
	}
	*/
	
}
void enque(int p,int pr){
		node *newnode=new node;
//	newnode->next=NULL;
	newnode->data=p;
	newnode->pr=p;
	if(head==NULL){
		newnode->next=NULL;
			head=newnode;
	}
	else{
		if(pr > head->pr){
			newnode->next=head;
			head =newnode;
			
		}
		else
		{
			node *curr=head;
			while(curr->next != NULL && curr->next->pr > pr)
			curr=curr->next;
			newnode->next=curr->next;
			curr->next=newnode;
		}
	}
}
int front()
{
	if(head==NULL)
	return -1;
	return head->data;
	
}
void display()
{
	cout<<"dfg";
	node *curr=head;
	while(curr!= NULL){
		cout<<curr->data<<endl;
		curr=curr->next;
		
	}
}

int main()
{
	
	
		while(1){
	
	cout<<"1. for enque"<<endl;
	cout<<"2. for display"<<endl;
	cout<<"3. for front"<<endl;
	cout<<"5. for dequeue"<<endl;
	cout<<"4. for exit"<<endl;
	cout<<"enter your choice"<<endl;
	int ch,p,d;
	cin>>ch;
	switch (ch){
		case 1:
			cout<<"enter the data you want to enter"<<endl;
			cin>>d;
			
			cout<<"enter the priority"<<endl;
			cin>>p;
			enque(d,p);
			break;
			case 2:
			//	cout<<"the deleted item is"<<endl;
				display();
				break;
				case 3:
				cout<<front()<<endl;
					break;
					case 4:
						exit(0);
						break;
						case 5:
							cout<<del()<<endl;
							break;
							
						
	
}

}
}
