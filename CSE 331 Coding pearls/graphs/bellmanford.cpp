#include<bits/stdc++.h>
using namespace std;

struct edge{
	int u,v,w;
};

void addedge(int u,int v,int w,vector<edge> &vu){

edge e;
e.u=u;
e.v=v;
e.w=w;
vu.push_back(e);
}

void bellmanford(int s,vector<edge> &v){
	int dist[4];
	for(int i=0;i<4;i++)
		dist[i]=INT_MAX;
		dist[s]=0;
		for(int i=0;i<3;i++){
		for(int j=0;j<v.size();j++){
			int src=v[j].u;
			int dest=v[j].v;
			int wt=v[j].w;
			if(dist[dest]>dist[src]+wt)
				dist[dest]=dist[src]+wt;
		}	
}
	for(int j=0;j<v.size();j++){
			int src=v[j].u;
			int dest=v[j].v;
			int wt=v[j].w;
			if(dist[dest]>dist[src]+wt)
				cout<<"negative";
		}	
for(int i=0;i<4;i++)
cout<<0<<" -->"<<i<<" "<<dist[i]<<endl;
}
int main(){

	
	vector<edge> v;
	addedge(0,1,2,v);
	addedge(0,2,3,v);
	addedge(2,1,-2,v);
	addedge(2,3,3,v);
	
	bellmanford(0,v);
	
	
}
