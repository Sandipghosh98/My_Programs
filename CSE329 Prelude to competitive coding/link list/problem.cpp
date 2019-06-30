#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node{
	int info;
	struct node *link;
}*start,*pre,*ptr,*loc,*p;

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
	while (ptr->info!=NULL){
		loc=ptr;
		p=ptr;
		while(p->ptr->next !=NULL)
		
	}
	
	
	
	
}
