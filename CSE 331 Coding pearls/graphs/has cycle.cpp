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

void dfs(int s, bool visited[], list<int> *adj){
	visited[s]=true;
	cout<<s<<" ";
	for(int i=0;i<5;i++){
	
		for(list<int> :: iterator it=adj[i].begin(); it!=adj[i].end(); it++)
		if(!visited[*it])
			dfs(*it,visited,adj);
	}
}
void checkCycle(int s,int parent,bool visited,list){
	cout<<"source : "<<s<<"  parent: "<<parent;
	visited[s]=true;
		for(list<int> :: iterator it=adj[s].begin(); it!=adj[s].end(); it++)
			if(!visited[*it])
				checkCycle(*it,s,visited,adj);
			if(!visited[])
				hasCycle=true;
			
}

void checkCycle1(int s,int parent,bool visited,list){
	cout<<"source : "<<s<<"  parent: "<<parent;
	visited[s]=true;
		for(list<int> :: iterator it=adj[s].begin(); it!=adj[s].end(); it++)
			if(!visited[*it])
				checkCycle(*it,s,visited,adj);
			else if(it !=true)
				hasCycle=true;
			
}
int main(){
list<int> *adj=new list<int>[5];
bool visited[5]={},hasCycle=false;
	addedge(0,1,adj);
		addedge(0,2,adj);
			addedge(2,3,adj);
				addedge(2,4,adj);
				
	display(adj);
	dfs(0,visited,adj);
}
