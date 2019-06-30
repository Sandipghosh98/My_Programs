#include<bits/stdc++.h>
#include<vector>
#include<list>
using namespace std;

void addedge(int u,int v,list<int> *adj){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void display(list<int> *adj){
	
	for(int i=0;i<5;i++){
		cout<<"vertex: "<<i<<endl;
		for(list<int> :: iterator it=adj[i].begin(); it!=adj[i].end(); it++)
			cout<<*it<<" "<<endl;
	}
	
}



int main(){
	
list<int> *adj=new list<int>[5];

	addedge(0,1,adj);
		addedge(0,2,adj);
			addedge(2,3,adj);
				addedge(2,4,adj);
				
	display(adj);
	
}
