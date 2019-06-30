#include<bits/stdc++.h>
using namespace std;

struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 

struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data  = data; 
    node->left  = node->right = NULL; 
    return(node); 
} 
struct link_list{
	int data;
	node *next;
};

int main(){
	
	int v,u,e;
	cout<<"number of vertics";
	cin>>v;
		int g[v][v];
	struct link_list *head[v];
	for(int i=0;i<v;i++){
		cout<<"enter the edges connect to "<<i+1<<" this vertics";
		cin>>e;
		for(int j=0;j<e;j++){
			cout<<"enter the node";
			cin>>u;
			head[v].data=u;
			g[i][u-1]=1;
		}
	}

	
}
