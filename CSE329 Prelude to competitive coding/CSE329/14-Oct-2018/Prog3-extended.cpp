#include<bits/stdc++.h>
using namespace std; 
  
struct Job { 
   char id[5];     
   int ti, pi;  
}; 
  
bool compare(Job a, Job b) { 
    return (a.pi > b.pi); 
}
  
void printJobs(Job arr[], int n) 
{ 
    sort(arr, arr+n, compare);

    int result[n]; 
    bool slot[n];  
  
    for (int i=0; i<n; i++) 
        slot[i] = false; 
  
    for (int i=0; i<n; i++) 
    { 
       for (int j=min(n, arr[i].ti)-1; j>=0; j--) 
       { 
          if (slot[j]==false) 
          { 
             result[j] = i;  
             slot[j] = true; 
             break; 
          } 
       } 
    } 
  
    for (int i=0; i<n; i++) 
       if (slot[i]) 
         cout << arr[result[i]].id << " "; 
} 
  
int main() 
{ 
    Job arr[] = { {"j1", 2, 16}, {"j2", 1, 4}, {"j3", 1, 2}, {"j4", 3, 3} }; 
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printJobs(arr, n);
    return 0; 
}