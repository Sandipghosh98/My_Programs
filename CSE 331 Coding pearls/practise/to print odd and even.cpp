#include<bits/stdc++.h>
using namespace std;
#include<queue>


struct node{
	int data;
	node *left,*right;
};

node* newNode(int data){
	node* ab=new node;
	ab->data=data;
	ab->left=NULL;
	ab->right=NULL;
	return ab;
}
vector<int>e;
vector<int>o;
node* makeBST(node *ro,int v){
//	node* temp=ro;
	if(ro==NULL)
	ro=newNode(v);
	else if(ro->data<v)
	ro->right=makeBST(ro->right,v);
	else
	ro->left=makeBST(ro->left,v);
	
	return ro;
	}
	
		void inorder(node *ro){
	if(ro==NULL)
		return;
		int w;
			inorder(ro->left);
			if(ro->data%2==0){
				w=ro->data;
			//	cout<<ro->data<<" ";
			e.push_back(w);
		
			//cout<<ro->data<<" ";
			}
			else{
					w=ro->data;
				//	cout<<ro->data<<" ";
					o.push_back (w);
			//	o.push(w);
			}
			inorder(ro->right);
	
}

int main(){
	int arr[]={8,10,6,5,12,9,7};
	int n=7;
	int val;
	node* root=newNode(arr[0]);
//	node* root1=makeBST(arr,1,n-1,root);
	for(int i=1;i<n;i++){
	val=arr[i];
	makeBST(root,val);
}
inorder(root);

for(int i=0;i<e.size();i++){
	cout<<e[i]<<" ";
}
cout<<endl;
for(int i=0;i<o.size();i++){
	cout<<o[i]<<" ";
}

}
