// Greedy Algorithm. Job Sequencing Problem (Loss Minimization).

#include <bits/stdc++.h>
using namespace std;

struct Job{
    int id,li,ti;
};

bool cmp(Job a, Job b) {
    return a.li * b.ti > b.li * a.ti;
}

void opt_seq(Job arr[], int n) {
    for(int i=0;i<n;i++)    cout<<arr[i].id<<" ";
}

int main() 
{ 
    Job arr[] = {{1,2,4}, {2,3,1000}, {3,4,2}, {4,1,5}}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, cmp);
    opt_seq(arr,n);
    return 0; 
}

/*
2   3       4   1       :   li
4   1000    2   5       :   ti

1   2       3   4       :   JobNum
0.5 0.003   2   0.2     :   ratio (li/ti)

arrange in desc order

output = 3 1 4 2
*/