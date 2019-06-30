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


