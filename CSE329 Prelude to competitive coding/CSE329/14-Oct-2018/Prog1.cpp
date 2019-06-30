// Greedy Algorithm. Job Sequencing Problem.

#include <bits/stdc++.h>
using namespace std; 
#define all(c) c.begin(), c.end() 

typedef pair<int, pair<int, int> > job; 

bool cmp_pair(job a, job b) 
{ 
    int a_Li, a_Ti, b_Li, b_Ti; 
    a_Li = a.second.first; 
    a_Ti = a.second.second; 
    b_Li = b.second.first; 
    b_Ti = b.second.second; 
  
    return (a_Li * b_Ti) > (b_Li * a_Ti); 
} 
  
void printOptimalPath(int L[], int T[], int N) 
{ 
    vector<job> list;
  
    for (int i = 0; i < N; i++) { 
        int t = T[i]; 
        int l = L[i]; 
  
        list.push_back(make_pair(i + 1, make_pair(l, t))); 
    } 
  
    stable_sort(all(list), cmp_pair); 

    cout << "Job numbers in optimal sequence are\n"; 
    for (int i = 0; i < N; i++)  
        cout << list[i].first << " ";    
  
} 
int main() 
{ 
    int L[] = { 2, 3, 4, 1}; 
    int T[] = { 4, 1000, 2, 5}; 
    int N = sizeof(L) / sizeof(L[0]); 
    printOptimalPath(L, T, N); 
    return 0; 
} 
