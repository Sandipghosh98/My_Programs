// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include<iostream> 
#include<list> 
using namespace std; 

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices 

	// Pointer to an array containing 
	// adjacency lists 
	list<int> *adj; 

	// A recursive function used by DFS 
	void DFSUtil(int v, bool visited[]); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// DFS traversal of the vertices 
	// reachable from v 
	void DFS(int v); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph::DFSUtil(int v, bool visited[]) 
{ 
	// Mark the current node as visited and 
	// print it 
	visited[v] = true; 
	cout << v << " "; 

	// Recur for all the vertices adjacent 
	// to this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited); 
} 

// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSUtil(v, visited); 
} 

int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n"; 
	g.DFS(2); 





  bool g[5][5];
  void dfs(int s,bool marked[]){
  	marked[s]=true;
  	cout<<s<<" ";
  	
  	for(int i=0;i<5;i++){
  		if(g[s][i] && !marked[i])
  			dfs(i,marked);
  	}
  }
  
  void add(int u,int v){
  	g[u][v]=g[v][u]=1;
  }
  
  
  int main(){
  	bool marked[5]={};
  	add(0,1);
  	add(0,2);
  	add(0,3);
  	add(3,4);
  
  	
  	dfs(0,marked);
  }
	return 0; 
} 
********************************************************************************

bfs in graph 

#include<iostream> 
#include <list> 
  
using namespace std; 
  
// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency 
    // lists 
    list<int> *adj;    
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w);  
  
    // prints BFS traversal from a given source s 
    void BFS(int s);   
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::BFS(int s) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 
  
// Driver program to test methods of graph class 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0; 
} 

********************************************************************************
cyccle in undirected graph

// A C++ Program to detect cycle in an undirected graph 
#include<iostream> 
#include <list> 
#include <limits.h> 
using namespace std; 

// Class for an undirected graph 
class Graph 
{ 
	int V; // No. of vertices 
	list<int> *adj; // Pointer to an array containing adjacency lists 
	bool isCyclicUtil(int v, bool visited[], int parent); 
public: 
	Graph(int V); // Constructor 
	void addEdge(int v, int w); // to add an edge to graph 
	bool isCyclic(); // returns true if there is a cycle 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
	adj[w].push_back(v); // Add v to w’s list. 
} 

// A recursive function that uses visited[] and parent to detect 
// cycle in subgraph reachable from vertex v. 
bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
	// Mark the current node as visited 
	visited[v] = true; 

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
	{ 
		// If an adjacent is not visited, then recur for that adjacent 
		if (!visited[*i]) 
		{ 
		if (isCyclicUtil(*i, visited, v)) 
			return true; 
		} 

		// If an adjacent is visited and not parent of current vertex, 
		// then there is a cycle. 
		else if (*i != parent) 
		return true; 
	} 
	return false; 
} 

// Returns true if the graph contains a cycle, else false. 
bool Graph::isCyclic() 
{ 
	// Mark all the vertices as not visited and not part of recursion 
	// stack 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function to detect cycle in different 
	// DFS trees 
	for (int u = 0; u < V; u++) 
		if (!visited[u]) // Don't recur for u if it is already visited 
		if (isCyclicUtil(u, visited, -1)) 
			return true; 

	return false; 
} 

// Driver program to test above functions 
int main() 
{ 
	Graph g1(5); 
	g1.addEdge(1, 0); 
	g1.addEdge(0, 2); 
	g1.addEdge(2, 0); 
	g1.addEdge(0, 3); 
	g1.addEdge(3, 4); 
	g1.isCyclic()? cout << "Graph contains cycle\n": 
				cout << "Graph doesn't contain cycle\n"; 

	Graph g2(3); 
	g2.addEdge(0, 1); 
	g2.addEdge(1, 2); 
	g2.isCyclic()? cout << "Graph contains cycle\n": 
				cout << "Graph doesn't contain cycle\n"; 

	return 0; 
} 
*************************************************************************************

bellman ford

// A C++ program for Bellman-Ford's single source 
// shortest path algorithm. 
#include <bits/stdc++.h> 

// a structure to represent a weighted edge in graph 
struct Edge 
{ 
	int src, dest, weight; 
}; 

// a structure to represent a connected, directed and 
// weighted graph 
struct Graph 
{ 
	// V-> Number of vertices, E-> Number of edges 
	int V, E; 

	// graph is represented as an array of edges. 
	struct Edge* edge; 
}; 

// Creates a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 
	graph->edge = new Edge[E]; 
	return graph; 
} 

// A utility function used to print the solution 
void printArr(int dist[], int n) 
{ 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < n; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// The main function that finds shortest distances from src to 
// all other vertices using Bellman-Ford algorithm. The function 
// also detects negative weight cycle 
void BellmanFord(struct Graph* graph, int src) 
{ 
	int V = graph->V; 
	int E = graph->E; 
	int dist[V]; 

	// Step 1: Initialize distances from src to all other vertices 
	// as INFINITE 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX; 
	dist[src] = 0; 

	// Step 2: Relax all edges |V| - 1 times. A simple shortest 
	// path from src to any other vertex can have at-most |V| - 1 
	// edges 
	for (int i = 1; i <= V-1; i++) 
	{ 
		for (int j = 0; j < E; j++) 
		{ 
			int u = graph->edge[j].src; 
			int v = graph->edge[j].dest; 
			int weight = graph->edge[j].weight; 
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
				dist[v] = dist[u] + weight; 
		} 
	} 

	// Step 3: check for negative-weight cycles. The above step 
	// guarantees shortest distances if graph doesn't contain 
	// negative weight cycle. If we get a shorter path, then there 
	// is a cycle. 
	for (int i = 0; i < E; i++) 
	{ 
		int u = graph->edge[i].src; 
		int v = graph->edge[i].dest; 
		int weight = graph->edge[i].weight; 
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
			printf("Graph contains negative weight cycle"); 
	} 

	printArr(dist, V); 

	return; 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph 
	int E = 8; // Number of edges in graph 
	struct Graph* graph = createGraph(V, E); 

	// add edge 0-1 (or A-B in above figure) 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 
	graph->edge[0].weight = -1; 

	// add edge 0-2 (or A-C in above figure) 
	graph->edge[1].src = 0; 
	graph->edge[1].dest = 2; 
	graph->edge[1].weight = 4; 

	// add edge 1-2 (or B-C in above figure) 
	graph->edge[2].src = 1; 
	graph->edge[2].dest = 2; 
	graph->edge[2].weight = 3; 

	// add edge 1-3 (or B-D in above figure) 
	graph->edge[3].src = 1; 
	graph->edge[3].dest = 3; 
	graph->edge[3].weight = 2; 

	// add edge 1-4 (or A-E in above figure) 
	graph->edge[4].src = 1; 
	graph->edge[4].dest = 4; 
	graph->edge[4].weight = 2; 

	// add edge 3-2 (or D-C in above figure) 
	graph->edge[5].src = 3; 
	graph->edge[5].dest = 2; 
	graph->edge[5].weight = 5; 

	// add edge 3-1 (or D-B in above figure) 
	graph->edge[6].src = 3; 
	graph->edge[6].dest = 1; 
	graph->edge[6].weight = 1; 

	// add edge 4-3 (or E-D in above figure) 
	graph->edge[7].src = 4; 
	graph->edge[7].dest = 3; 
	graph->edge[7].weight = -3; 

	BellmanFord(graph, 0); 

	return 0; 
} 

*********************************************************************************
find a path in a graph

#include<bits/stdc++.h>
using namespace std;


void addedge(int u, int v,vector<vector<int> >&adj){
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void dfs(int src,vector<vector<int> >&adj,int *vis)
{
    vis[src]=1;
    for(int i=0;i<adj[src].size();i++)
    {
        if(!vis[adj[src][i]])
            dfs(adj[src][i],adj,vis);
    }
}
bool findpath(int u, int v,vector<vector<int> >&adj){
    int n=adj.size();
    
    int *vis=new int[n];
    memset(vis,0,n*sizeof(int));
    dfs(u,adj,vis);
    
    if(vis[v]==1)
        return true;
    else
        return false;
  //Your Code Here
}

int main(){
    int vertices, edges, u, v;
    cin>>vertices>>edges;
    vector<vector<int> >adj(vertices+1);
    for(int i = 0; i < edges; i++){
      cin>>u>>v;
      addedge(u, v, adj);
    }
    cin>>u>>v;
    if(findpath(u, v, adj))
      cout<<"yes";
    else
      cout<<"no";
}
*****************************************************************

dijastra algo

// Program to find Dijkstra's shortest path using 
// priority_queue in STL 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 

// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices 

	// In a weighted graph, we need to store vertex 
	// and weight pair for every edge 
	list< pair<int, int> > *adj; 

public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int u, int v, int w); 

	// prints shortest path from s 
	void shortestPath(int s); 
}; 

// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<iPair> [V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src) 
{ 
	// Create a priority queue to store vertices that 
	// are being preprocessed. This is weird syntax in C++. 
	// Refer below link for details of this syntax 
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/ 
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 
	vector<int> dist(V, INF); 

	// Insert source itself in priority queue and initialize 
	// its distance as 0. 
	pq.push(make_pair(0, src)); 
	dist[src] = 0; 

	/* Looping till priority queue becomes empty (or all 
	distances are not finalized) */
	while (!pq.empty()) 
	{ 
		// The first vertex in pair is the minimum distance 
		// vertex, extract it from priority queue. 
		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted distance (distance must be first item 
		// in pair) 
		int u = pq.top().second; 
		pq.pop(); 

		// 'i' is used to get all adjacent vertices of a vertex 
		list< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = (*i).first; 
			int weight = (*i).second; 

			// If there is shorted path to v through u. 
			if (dist[v] > dist[u] + weight) 
			{ 
				// Updating distance of v 
				dist[v] = dist[u] + weight; 
				pq.push(make_pair(dist[v], v)); 
			} 
		} 
	} 

	// Print shortest distances stored in dist[] 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < V; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	// create the graph given in above fugure 
	int V = 10; 
	Graph g(V); 

	// making above shown graph 
	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 
	g.addEdge(0, 9, 7); 
	g.shortestPath(2); 

	return 0; 
} 
*********************************************************************************

floyee warshall

#include<stdio.h>
int min(int,int);

int min(int a,int b)
{
 if(a<b)
  return(a);
 else
  return(b);
}
int main()
{
 int p[10][10],w,n,e,u,v,i,j;;
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 printf("\n Enter the number of edges:\n");
 scanf("%d",&e);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   p[i][j]=999;
 }
 for(i=1;i<=e;i++)
 {
  printf("\n Enter the end vertices of edge%d with its weight \n",i);
  scanf("%d%d%d",&u,&v,&w);
  p[u][v]=w;
 }
 printf("\n Matrix of input data:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%d \t",p[i][j]);
  printf("\n");
 }

 
 
 //int i,j,k;
 int x,y,z;
 for(z=1;z<=n;z++)
  for(x=1;x<=n;x++)
   for(y=1;y<=n;y++)
    if(x==j)
     p[x][y]=0;
    else
     p[x][y]=min(p[x][y],p[x][z]+p[z][y]);
 
 
 
 
 
 
 
 
 
 printf("\n Transitive closure:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%d \t",p[i][j]);
  printf("\n");
 }
 printf("\n The shortest paths are:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   if(i!=j)
    printf("\n <%d,%d>=%d",i,j,p[i][j]);
  }
}

************************************************************************************

prism algo

#include <iostream>
#include <cstring>
using namespace std;
 
#define INF 9999999
 
// number of vertices in grapj

 
// create a 2d array of size 5x5
//for adjacency matrix to represent graph
 

 
int main () {
  const int V=5;
 int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
};
 
 
  int no_edge;            // number of edge
 
  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[V];
  
 // set selected false initially
  memset (selected, false, sizeof (selected));
 
 // set number of edge to 0
  no_edge = 0;
 
  // the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph
 
  // choose 0th vertex and make it true
  selected[0] = true;
 
  int x;            //  row number
  int y;            //  col number
 
  // print for edge and weight
  cout << "Edge" << " : " << "Weight";
  cout << endl;
  while (no_edge < V - 1) {
 
  //For every vertex in the set S, find the all adjacent vertices
  // , calculate the distance from the vertex selected at step 1.
  // if the vertex is already in the set S, discard it otherwise
  //choose another vertex nearest to selected vertex  at step 1.
 
      int min = INF;
      x = 0;
      y = 0;
 
      for (int i = 0; i < V; i++) {
        if (selected[i]) {
            for (int j = 0; j < V; j++) {
              if (!selected[j] && G[i][j]) { // not in selected and there is an edge
                  if (min > G[i][j]) {
                      min = G[i][j];
                      x = i;
                      y = j;
                  }
     
              }
          }
        }
      }
      cout << x <<  " - " << y << " :  " << G[x][y];
      cout << endl;
      selected[y] = true;
      no_edge++;
    }
 
  return 0;
}

*****************************************************************************************
bipartile graph

// C++ program to find out whether a 
// given graph is Bipartite or not 
#include <iostream> 
#include <queue> 
//#define V 4 
#include<bits/stdc++.h>
using namespace std; 

// This function returns true if graph 
// G[V][V] is Bipartite, else false 


// Driver program to test above function 
int main() 
{ 
const int V=4; 
	int G[][V] = {{0, 1, 0, 1}, 
		{1, 0, 1, 0}, 
		{0, 1, 0, 1}, 
		{1, 0, 1, 0} 
	}; 

int src=0;
	
	
		// second color is assigned. 
	int colorArr[V]; 
	for (int i = 0; i < V; ++i) 
		colorArr[i] = -1; 

	// Assign first color to source 
	colorArr[src] = 1; 

	// Create a queue (FIFO) of vertex 
	// numbers and enqueue source vertex 
	// for BFS traversal 
	queue <int> q; 
	q.push(src); 

	// Run while there are vertices 
	// in queue (Similar to BFS) 
	while (!q.empty()) 
	{ 
		// Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
		int u = q.front(); 
		q.pop(); 

		// Return false if there is a self-loop 
		if (G[u][u] == 1) {
		
		cout<<"no";
				exit(0); 
		}
		// Find all non-colored adjacent vertices 
		for (int v = 0; v < V; ++v) 
		{ 
			// An edge from u to v exists and 
			// destination v is not colored 
			if (G[u][v] && colorArr[v] == -1) 
			{ 
				// Assign alternate color to this adjacent v of u 
				colorArr[v] = 1 - colorArr[u]; 
				q.push(v); 
			} 

			// An edge from u to v exists and destination 
			// v is colored with same color as u 
			else if (G[u][v] && colorArr[v] == colorArr[u]) {
				cout<<"no";
				exit(0); 
			}
		} 
	} 

	// If we reach here, then all adjacent 
	// vertices can be colored with alternate color 
	cout<<"yes";
	
	
	return 0; 
} 


