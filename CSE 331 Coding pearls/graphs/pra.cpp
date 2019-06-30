// C++ implementation of the approach 
#include <bits/stdc++.h> 
#include <vector>
using namespace std; 

// Function to return the number 
// of unique pairs in the array 
int countUnique(int arr[], int n) 
{ 

	// Set to store unique pairs 
	set<pair<int, int> > s; 

	// Make all possible pairs 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			s.insert(make_pair(arr[i], arr[j])); 


	for (int i = 0; i < s.size(); i++) {
	
	cout<<s[i].first<<" "<<s[i].second;
	cout<<endl;
		}
	// Return the size of the set 
	return s.size(); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 2, 2, 4, 2, 5, 3, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << countUnique(arr, n); 
	
	return 0; 
} 

