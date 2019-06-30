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
void checkCycle(int s,int parent,bool visited, list<int> * list){
	cout<<"source : "<<s<<"  parent: "<<parent;
	visited[s]=true;
		for(list<int> :: iterator it=adj[s].begin(); it!=adj[s].end(); it++)
			if(!visited[*it])
				checkCycle(*it,s,visited,adj);
			else if(it !=true)
				hasCycle=true;
			
}

void bi(int s, bool color,  bool visited, list<int> *adj, bool &colorable)
visited[s]=true;
	for(list<int> :: iterator it=adj[s].begin(); it!=adj[s].end(); it++)
		if(!visited[*it]){
			color[*it]=!color[s];
			bi(*it,color,visited,adj,color2);
		}
		else if(color[*it]==color[s])
			color2=false;
		}

int main(){
list<int> *adj=new list<int>[5];
bool visited[5]={},hasCycle=false,colorable2=true;
bool color[4]={}
	addedge(0,1,adj);
		addedge(0,2,adj);
			addedge(2,3,adj);
				addedge(1,2,adj);
				
//	display(adj);
//	dfs(0,visited,adj);
	
	
	for(int i=0;i<4;i++)
	if(!visited[i])
	bi(i,color,visited,adj);
	if(colorable2)
		cout<<"bipartite graph";
	else
		cout<<"not bipartite graph";
}
