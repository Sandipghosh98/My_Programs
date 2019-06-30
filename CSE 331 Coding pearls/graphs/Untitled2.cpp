#include<bits/stdc++.h>
using namespace std;
void addedge(int u,int v,list<int> *adj)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void print(list<int> *adj)
{
	for(int i=0;i<4;i++){
		cout<<"VERTIX: "<<i<<endl;
		for(list<int>::iterator it=adj[i].begin();it!=adj[i].end();it++)
			cout<<*it<<" ";
		cout<<endl;
	}
		
}
void dfs(int s,bool visited[],list<int> *adj)
{
	visited[s]=true;
	cout<<s<<" ";
	for(list<int>::iterator it=adj[s].begin();it!=adj[s].end();it++)
		if(!visited[*it])
			dfs(*it,visited,adj);
}
void checkCycle(int s,int parent,bool visited[], list<int> *adj,bool &hasCycle)
{
	//cout<<"Sourse: "<<s<<"PARENT: "<<parent<<endl;
	visited[s]=true;
	for(list<int>::iterator it=adj[s].begin();it!=adj[s].end();it++)
		if(!visited[*it])
			checkCycle(*it,s,visited,adj,hasCycle);
		else if(*it!=parent)
		{
			hasCycle=true;
			cout<<"Sourse: "<<s<<"PARENT: "<<parent<<endl;
		}
}
void bipartite(int s, bool colour[], bool visited[], list<int> *adj,bool &_2colourable)
{
	visited[s]=true;
	for(list<int>::iterator it=adj[s].begin();it!=adj[s].end();it++)
		if(!visited[*it])
		{
			colour[*it]=!colour[s];
			bipartite(*it,colour,visited,adj,_2colourable);
		}
		else if(colour[*it]==colour[s])
			_2colourable=true;
}

int main()
{
	list<int> *adj=new list<int>[6];
	bool visited[4]={}, hasCycle= false,_2colourable=true, colour[4]={};
	addedge(0,1,adj);
	addedge(0,2,adj);
	addedge(1,3,adj);
	addedge(3,5,adj);
	print(adj);
	dfs(0,visited,adj);
/*	for(int i=0;i<4;i++)
		if(!visited[i])
			checkCycle(i,-1,visited,adj,hasCycle);
	if(hasCycle)
		cout<<"Cycyle"<<endl;
	else
		cout<<"NO CYCLE"<<endl;
	*/
	for(int i=0;i<4;i++)
		if(!visited[i])
			bipartite(i,colour,visited,adj,_2colourable);
		if(_2colourable)
			cout<<"Bipartite"<<endl;
		else
			cout<<"NOT BIPARTATE"<<endl;
		
}
