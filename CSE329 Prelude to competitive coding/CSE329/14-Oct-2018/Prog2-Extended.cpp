// Greedy Algorithm. Job Selection (Minimizing Loss - Part 2).

#include<bits/stdc++.h>
using namespace std;

double max_vol(int a[], int n, double p)
{
    double ans = 0;
    for(int i=0;i<n;i++)
        ans += pow((1-p),n-1-i) * a[i];
    return ans;
}

int main()
{
    int a[] = {70,80,10,20};
    int n = sizeof(a)/sizeof(a[0]);
    double p = 0.1;
    sort(a,a+n);
    cout<<max_vol(a,n,p);
}